#include "../../include/utils/TSort.h"
using namespace std;


/*=========================================================================

                               MERGESORT

=========================================================================*/


/**
 * @brief Splits a doubly-linked list into two halves.
 * @return Pointer to the head of the second half.
 */
template <typename T>
static TNode<T>* SplitList(TNode<T>* head)
{
    if (!head || !head->next)
        return nullptr;

    TNode<T>* slow = head;
    TNode<T>* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    TNode<T>* second = slow->next;
    slow->next = nullptr;
    if (second) second->prev = nullptr;
    return second;
}

/**
 * @brief Merges two sorted linked lists into one sorted list.
 */
template <typename T, typename Compare>
static TNode<T>* MergeLists(TNode<T>* left, TNode<T>* right,
                            Compare compare, long long& comparisons, long long& swaps)
{
    if (!left) return right;
    if (!right) return left;

    TNode<T>* result = nullptr;

    if (compare(left->data, right->data) <= 0) {
        comparisons++;
        result = left;
        result->next = MergeLists(left->next, right, compare, comparisons, swaps);
        if (result->next) result->next->prev = result;
    } else {
        comparisons++;
        result = right;
        result->next = MergeLists(left, right->next, compare, comparisons, swaps);
        if (result->next) result->next->prev = result;
        swaps++;
    }

    return result;
}

/**
 * @brief Recursive merge sort helper for linked lists.
 */
template <typename T, typename Compare>
static TNode<T>* MergeSortRec(TNode<T>* head,
                              Compare compare,
                              long long& comparisons,
                              long long& swaps)
{
    if (!head || !head->next)
        return head;

    TNode<T>* second = SplitList(head);

    head = MergeSortRec(head, compare, comparisons, swaps);
    second = MergeSortRec(second, compare, comparisons, swaps);

    return MergeLists(head, second, compare, comparisons, swaps);
}

template <typename T, typename Compare>
void TSort::MergeSort(TLinkedList<T>& list, Compare compare, OperationSummary& summary)
{
    auto start = std::chrono::high_resolution_clock::now();
    summary.comparisons = summary.swaps = 0;

    if (list.Head()) {
        // Recursive sorting
        TNode<T>* newHead = MergeSortRec(list.Head(), compare,
                                         summary.comparisons, summary.swaps);
        list.SetHead(newHead);

        // Update tail
        TNode<T>* node = newHead;
        while (node && node->next)
            node = node->next;
        list.SetTail(node);
    }

    auto end = std::chrono::high_resolution_clock::now();
    summary.timeSpentMs =
        std::chrono::duration<double, std::milli>(end - start).count();
}



/*=========================================================================

                               QUICKSORT

=========================================================================*/


    /**
     * @brief Swaps two elements in the array and updates swap counter.
     */
    template <typename T>
    static inline void Swap(std::vector<T*>& arr, int i, int j, long long& swaps) {
    std::swap(arr[i], arr[j]);
    swaps++;
}

/**
 * @brief Partition function for QuickSort.
 */
template <typename T, typename Compare>
static int Partition(std::vector<T*>& arr, int low, int high,
                     long long& comparisons, long long& swaps, Compare compare)
{
    T* pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        comparisons++;
        if (compare(arr[j], pivot) < 0) {
            i++;
            Swap(arr, i, j, swaps);
        }
    }
    Swap(arr, i + 1, high, swaps);
    return i + 1;
}

/**
 * @brief Recursive QuickSort helper.
 */
template <typename T, typename Compare>
static void QuickSortRec(std::vector<T*>& arr, int low, int high,
                         long long& comparisons, long long& swaps, Compare compare)
{
    if (low < high) {
        int pivotIndex = Partition(arr, low, high, comparisons, swaps, compare);
        QuickSortRec(arr, low, pivotIndex - 1, comparisons, swaps, compare);
        QuickSortRec(arr, pivotIndex + 1, high, comparisons, swaps, compare);
    }
}

template <typename T, typename Compare>
void TSort::QuickSort(std::vector<T*>& arr, Compare compare, OperationSummary& summary)
{
    auto start = std::chrono::high_resolution_clock::now();
    summary.comparisons = summary.swaps = 0;

    if (!arr.empty())
        QuickSortRec(arr, 0, static_cast<int>(arr.size()) - 1,
                     summary.comparisons, summary.swaps, compare);

    auto end = std::chrono::high_resolution_clock::now();
    summary.timeSpentMs =
        std::chrono::duration<double, std::milli>(end - start).count();
}
