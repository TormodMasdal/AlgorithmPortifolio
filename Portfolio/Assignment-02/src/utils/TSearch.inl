#pragma once
#include <chrono>


template <typename T, typename Compare>
T* TSearch::BinarySearch(const std::vector<T*>& arr,
                         const T* key,
                         OperationSummary& summary,
                         Compare compare)
{
    auto start = std::chrono::high_resolution_clock::now();
    summary.comparisons = 0;
    summary.swaps = 0;   // Binary search does not swap, but it is kept for consistency

    if (arr.empty())
        return nullptr;

    int low  = 0;
    int high = static_cast<int>(arr.size()) - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        summary.comparisons++;

        int cmp = compare(key, arr[mid]);

        if (cmp == 0) {
            auto end = std::chrono::high_resolution_clock::now();
            summary.timeSpentMs =
                std::chrono::duration<double, std::milli>(end - start).count();
            return arr[mid];
        }
        else if (cmp < 0) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    summary.timeSpentMs =
        std::chrono::duration<double, std::milli>(end - start).count();

    return nullptr;
}