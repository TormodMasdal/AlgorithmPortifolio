#pragma once
#include "../include/TLinkedList.h"

template <typename T>
TLinkedList<T>::~TLinkedList() {
    Clear();
}

template <typename T>
void TLinkedList<T>::PushBack(T* item) {
    auto* node = new TNode<T>(item);
    if (!mHead) {
        mHead = mTail = node;
    } else {
        mTail->next = node;
        node->prev  = mTail;
        mTail       = node;
    }
    ++mSize;
}

template <typename T>
bool TLinkedList<T>::Remove(T* item) {
    for (auto* cur = mHead; cur; cur = cur->next) {
        if (cur->data == item) {
            if (cur->prev) cur->prev->next = cur->next; else mHead = cur->next;
            if (cur->next) cur->next->prev = cur->prev; else mTail = cur->prev;
            if (mOwnsData && cur->data) delete cur->data;
            delete cur;
            --mSize;
            return true;
        }
    }
    return false;
}

template <typename T>
void TLinkedList<T>::Clear() {
    auto* cur = mHead;
    while (cur) {
        auto* nxt = cur->next;
        if (mOwnsData && cur->data) delete cur->data;
        delete cur;
        cur = nxt;
    }
    mHead = mTail = nullptr;
    mSize = 0;
}