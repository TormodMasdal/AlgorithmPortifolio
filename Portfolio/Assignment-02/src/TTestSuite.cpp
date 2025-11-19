#include "../include/TTestSuite.h"
#include "../include/TCorporateDirectory.h"
#include "../include/utils/TSearch.h"

#include <iostream>
#include <iomanip>
#include <limits>

void TTestSuite::RunAll()
{
    // ============================================================
    // INITIALIZING AND DATA READING
    // ============================================================
    TCorporateDirectory directory;
    directory.LoadFromFile("random_names.txt");

    std::cout << "Loaded: " << directory.Count() << " employees\n";

    bool running = true;

    while (running)
    {
        // ========================================================
        // MENU
        // ========================================================
        std::cout << "\n========== MENU ==========\n";
        std::cout << "1. Print Linked List\n";
        std::cout << "2. Print Array\n";
        std::cout << "3. Apply MergeSort (List)\n";
        std::cout << "4. Apply QuickSort (Array)\n";
        std::cout << "5. Binary Search (First + Last)\n";
        std::cout << "0. Exit\n";
        std::cout << "==========================\n";
        std::cout << "Choose option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
            case 1: // PRINT LINKED LIST
            {
                std::cout << "How many to print? ";
                int n;
                std::cin >> n;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                directory.PrintPreview(n);
                break;
            }

            case 2: // PRINT ARRAY
            {
                std::cout << "How many to print? ";
                int n;
                std::cin >> n;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                directory.PrintPreviewArray(n);
                break;
            }

            case 3: // MERGE SORT (LINKED LIST)
            {
                OperationSummary summary;
                directory.SortByName_List(summary);

                std::cout << "\n=== MERGE SORT DONE ===\n";
                std::cout << "Comparisons: " << summary.comparisons << "\n";
                std::cout << "Swaps:       " << summary.swaps << "\n";
                std::cout << "Time (ms):   " << summary.timeSpentMs << "\n";
                break;
            }

            case 4: // QUICK SORT (ARRAY)
            {
                OperationSummary summary;
                directory.SortByDepartment(summary);

                std::cout << "\n=== QUICK SORT DONE ===\n";
                std::cout << "Comparisons: " << summary.comparisons << "\n";
                std::cout << "Swaps:       " << summary.swaps << "\n";
                std::cout << "Time (ms):   " << summary.timeSpentMs << "\n";
                break;
            }

            case 5: // BINARY SEARCH (FIRST + LAST NAME)
            {
                std::string firstName, lastName;

                std::cout << "\nEnter FIRST name: ";
                std::getline(std::cin, firstName);

                std::cout << "Enter LAST name: ";
                std::getline(std::cin, lastName);

                // Kopi av linked list som ER sortert på lastname -> firstname
                std::vector<TEmployee*> arrayCopy = directory.ToArrayFromList();

                // søke-nøkkel
                TEmployee searchKey(firstName, lastName, EDepartment::IT); // dept irrelevant

                // sammenligningslambda (lastname -> firstname)
                auto compareByName = [](const TEmployee* key, const TEmployee* current) -> int {
                    if (key->Last() == current->Last())
                    {
                        if (key->First() == current->First()) return 0;
                        return (key->First() < current->First()) ? -1 : 1;
                    }
                    return (key->Last() < current->Last()) ? -1 : 1;
                };

                OperationSummary searchSummary;
                TEmployee* result =
                    TSearch::BinarySearch(arrayCopy, &searchKey, searchSummary, compareByName);

                std::cout << "\n=== SEARCH RESULT ===\n";
                if (result)
                    std::cout << "Found: " << result->ToString() << "\n";
                else
                    std::cout << "Employee not found.\n";

                std::cout << "Search time: " << std::fixed << std::setprecision(3)
                          << searchSummary.timeSpentMs << " ms, "
                          << searchSummary.comparisons << " comparisons.\n";
                break;
            }

            case 0:
                running = false;
                break;

            default:
                std::cout << "Invalid choice.\n";
        }
    }
}