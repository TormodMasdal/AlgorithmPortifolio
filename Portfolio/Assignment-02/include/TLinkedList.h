#pragma once
#include <cstddef>

/**
 * @brief Node used in our doubly-linked list.
 * @details Stores a T* and links to previous/next nodes.
 */
template <typename T>
struct TNode {
    T* data { nullptr };
    TNode* next { nullptr };
    TNode* prev { nullptr };
    explicit TNode(T* d) : data(d) {}
};

/**
 * @brief Lightweight doubly-linked list implementation.
 * @details Can optionally "own" the data and clean it up on destruction.
 */
template <typename T>
class TLinkedList {
private:
    TNode<T>* mHead { nullptr };
    TNode<T>* mTail { nullptr };
    bool mOwnsData { true };
    std::size_t mSize { 0 };

public:
    explicit TLinkedList(bool ownsData = true)
        : mOwnsData(ownsData) {}

    ~TLinkedList();

    /// @brief Insert element at the end in O(1).
    void PushBack(T* item);

    /// @brief Find and remove the first node holding this pointer.
    bool Remove(T* item);

    /// @brief Wipe the list completely.
    void Clear();

    TNode<T>* Head() const { return mHead; }
    TNode<T>* Tail() const { return mTail; }
    std::size_t Size() const { return mSize; }

    bool OwnsData() const { return mOwnsData; }

    /// @brief Let external algorithms (like MergeSort) replace the head.
    void SetHead(TNode<T>* newHead) { mHead = newHead; }

    /// @brief Let external algorithms (like MergeSort) replace the tail.
    void SetTail(TNode<T>* newTail) { mTail = newTail; }
};

#include "../src/TLinkedList.cpp"
