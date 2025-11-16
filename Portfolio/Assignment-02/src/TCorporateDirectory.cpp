#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "../include/TCorporateDirectory.h"
#include "SharedLib.h"
#include "../include/utils/TSort.h"

// Static init
TCorporateDirectory* TCorporateDirectory::sActiveLoader = nullptr;

TCorporateDirectory::TCorporateDirectory()
    : mMasterList(true) // owns payloads
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

EDepartment TCorporateDirectory::RandomDepartment() {
    switch (std::rand() % 3) {
        case 0: return EDepartment::IT;
        case 1: return EDepartment::Finance;
        default: return EDepartment::HR;
    }
}

// C-style bridge required by FNameRead (no user data parameter)
bool TCorporateDirectory::OnNameReadBridge(int idx, int total,
                                           const std::string& first,
                                           const std::string& last)
{
    if (!sActiveLoader) return false;
    return sActiveLoader->OnNameRead(idx, total, first, last);
}

bool TCorporateDirectory::OnNameRead(int idx, int total,
                                     const std::string& first,
                                     const std::string& last)
{
    // Create on heap (directory/list owns)
    auto* emp = new TEmployee(first, last, RandomDepartment());

    // Insert into both structures
    mMasterList.PushBack(emp);
    mMasterArray.push_back(emp);

#ifdef DEBUG
    if ((idx + 1) % 500 == 0)
        std::cout << "Loaded " << (idx + 1) << "/" << total << " employees" << std::endl;
#endif
    return true;
}

void TCorporateDirectory::LoadFromFile(const std::string& filename) {
    sActiveLoader = this;
    readNamesFromFile(filename, &TCorporateDirectory::OnNameReadBridge);
    sActiveLoader = nullptr;
}

void TCorporateDirectory::PrintPreview(std::size_t limit) const
{
    std::cout << std::endl
              << "========================================" << std::endl
              << "EMPLOYEE DIRECTORY (showing first " << limit
              << " of " << mMasterArray.size() << ")" << std::endl
              << "========================================" << std::endl << std::endl;

    std::cout << std::left
              << std::setw(20) << "First Name"
              << std::setw(20) << "Last Name"
              << std::setw(15) << "Department" << std::endl
              << "--------------------------------------------------------------" << std::endl;

    auto* node = mMasterList.Head();
    std::size_t count = 0;

    while (node && count < limit) {
        const auto* e = node->data;
        std::string dept;
        switch (e->Department()) {
            case EDepartment::IT: dept = "IT"; break;
            case EDepartment::Finance: dept = "Finance"; break;
            case EDepartment::HR: dept = "HR"; break;
        }

        std::cout << std::left
                  << std::setw(20) << e->First()
                  << std::setw(20) << e->Last()
                  << std::setw(15) << dept
                  << std::endl;

        node = node->next;
        ++count;
    }

    std::cout << "--------------------------------------------------------------" << std::endl;
}

void TCorporateDirectory::SortByName_List(OperationSummary& summary)
{
    // Comparison: sort by last name, then first name
    auto compareByName = [](TEmployee* left, TEmployee* right) -> int {
        if (left->Last() == right->Last()) {
            if (left->First() == right->First()) return 0;
            return (left->First() < right->First()) ? -1 : 1;
        }
        return (left->Last() < right->Last()) ? -1 : 1;
    };

    // Perform merge sort directly on the linked list
    TSort::MergeSort(mMasterList, compareByName, summary);
}


void TCorporateDirectory::SortByDepartment(OperationSummary& summary)
{
    auto compareByDepartmentThenName = [](TEmployee* leftEmployee, TEmployee* rightEmployee) -> int {
        if (leftEmployee->Department() != rightEmployee->Department()) {
            const std::string leftDept  = leftEmployee->ToString().substr(leftEmployee->ToString().find('(') + 1, 1);
            const std::string rightDept = rightEmployee->ToString().substr(rightEmployee->ToString().find('(') + 1, 1);
            return leftDept < rightDept ? -1 : 1;
        }

        const std::string& leftLastName  = leftEmployee->Last();
        const std::string& rightLastName = rightEmployee->Last();
        if (leftLastName != rightLastName)
            return leftLastName < rightLastName ? -1 : 1;

        const std::string& leftFirstName  = leftEmployee->First();
        const std::string& rightFirstName = rightEmployee->First();
        if (leftFirstName != rightFirstName)
            return leftFirstName < rightFirstName ? -1 : 1;

        return 0;
    };

    TSort::QuickSort(mMasterArray, compareByDepartmentThenName, summary);
}

void TCorporateDirectory::PrintPreviewArray(std::size_t limit) const
{
    std::cout << std::endl
              << "========================================" << std::endl
              << "EMPLOYEE DIRECTORY (array, first " << limit
              << " of " << mMasterArray.size() << ")" << std::endl
              << "========================================" << std::endl << std::endl;

    std::cout << std::left
              << std::setw(20) << "First Name"
              << std::setw(20) << "Last Name"
              << std::setw(15) << "Department" << std::endl
              << "--------------------------------------------------------------" << std::endl;

    std::size_t n = std::min(limit, mMasterArray.size());
    for (std::size_t i = 0; i < n; ++i) {
        const auto* e = mMasterArray[i];
        const char* dept = (e->Department() == EDepartment::IT ? "IT" :
                           (e->Department() == EDepartment::Finance ? "Finance" : "HR"));
        std::cout << std::left
                  << std::setw(20) << e->First()
                  << std::setw(20) << e->Last()
                  << std::setw(15) << dept
                  << std::endl;
    }

    std::cout << "--------------------------------------------------------------" << std::endl;
}

std::vector<TEmployee*> TCorporateDirectory::ToArrayFromList() const {
    std::vector<TEmployee*> result;
    result.reserve(mMasterList.Size());
    for (auto* node = mMasterList.Head(); node; node = node->next)
        result.push_back(node->data);
    return result;
}
