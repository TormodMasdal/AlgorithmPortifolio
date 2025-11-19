#pragma once
#include <vector>
#include <chrono>
#include "OperationSummary.h"

/**
 * @brief Generic binary search helper.
 * @details Works on any sorted vector<T*> as long as we provide a compare function.
 */
class TSearch {
public:
    /**
     * @brief Runs a binary search on a sorted vector of pointers.
     * @tparam T       The data type (e.g., TEmployee).
     * @tparam Compare A function/lambda that tells us how two elements compare.
     * @param arr      Sorted array we search through.
     * @param key      The “thing” we’re looking for.
     * @param summary  Stats about how the search went.
     * @param compare  Custom compare(key, element) function.
     * @return Pointer to the match, or nullptr if not found.
     */
    template <typename T, typename Compare>
    static T* BinarySearch(const std::vector<T*>& arr,
                           const T* key,
                           OperationSummary& summary,
                           Compare compare);
};

#include "../../src/utils/TSearch.inl"