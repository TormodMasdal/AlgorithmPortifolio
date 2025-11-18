#pragma once
#include <vector>
#include <chrono>

#include "OperationSummary.h"

/**
 * @brief Generic sorting utilities used across the assignment.
 * @details Provides MergeSort for linked lists and QuickSort for vectors.
 */
class TSort {
public:
    /**
     * @brief MergeSort implementation for the TLinkedList<T>.
     * @details Sorts the list by relinking nodes (no copying into arrays).
     */
    template <typename T, typename Compare>
    static void MergeSort(TLinkedList<T>& list,
                          Compare compare,
                          OperationSummary& summary);

    /**
     * @brief QuickSort for std::vector<T*>.
     * @details Used mainly for the department-based sort.
     */
    template <typename T, typename Compare>
    static void QuickSort(std::vector<T*>& arr,
                          Compare compare,
                          OperationSummary& summary);
};

#include "../../src/utils/TSort.inl"
