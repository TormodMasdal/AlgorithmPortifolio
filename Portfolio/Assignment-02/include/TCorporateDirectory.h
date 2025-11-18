#pragma once
#include <vector>
#include <string>
#include "TEmployee.h"
#include "TLinkedList.h"
#include "utils/TSort.h"

/**
 * @brief Main container for all employees.
 * @details Stores the same employee objects in both a linked list and an array,
 *          since different tasks require different data structures.
 */
class TCorporateDirectory {
private:
    TLinkedList<TEmployee> mMasterList;         // owns employee objects
    std::vector<TEmployee*> mMasterArray;       // mirrors the list but does NOT own pointers

    // Needed because the file reader uses a C-style callback.
    static TCorporateDirectory* sActiveLoader;

    /// @brief Static bridge used by readNamesFromFile.
    static bool OnNameReadBridge(int idx, int total,
                                 const std::string& first,
                                 const std::string& last);

    /// @brief Called once for each name in the file.
    bool OnNameRead(int idx, int total,
                    const std::string& first,
                    const std::string& last);

    /// @brief Assigns a random department when loading names.
    static EDepartment RandomDepartment();

public:
    /// @brief Sets up the directory and linked list ownership settings.
    TCorporateDirectory();

    /// @brief Loads names from disk and fills both list and array.
    void LoadFromFile(const std::string& filename);

    /// @brief Small preview of the linked list.
    void PrintPreview(std::size_t limit = 10) const;

    /// @brief Total number of employees.
    std::size_t Count() const { return mMasterArray.size(); }

    TNode<TEmployee>* ListHead() const { return mMasterList.Head(); }
    const std::vector<TEmployee*>& Array() const { return mMasterArray; }

    /// @brief Sorts the linked list alphabetically (Lastname -> Firstname).
    void SortByName_List(OperationSummary& summary);

    /// @brief Sorts the array by Department -> Lastname -> Firstname.
    void SortByDepartment(OperationSummary& summary);

    void PrintPreviewArray(std::size_t limit = 50) const;

    /// @brief Builds a fresh array copy based on the sorted linked list.
    std::vector<TEmployee*> ToArrayFromList() const;
};
