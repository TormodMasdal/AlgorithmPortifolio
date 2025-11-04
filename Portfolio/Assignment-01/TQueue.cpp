#include "TQueue.h"
#include "iostream"
#include "TStack.h"

template<typename T>
TQueue<T>::TQueue(int aMaxSize) : size(aMaxSize) {
    arr = new T*[size];
}

template<typename T>
TQueue<T>::~TQueue() {
    delete[] arr;
}


// Time complexity O(1), Space complexity O(1)
template<typename T>
void TQueue<T>::Enqueue(T *aSong) {
    if (count == size - 1) {
        std::cout << "Queue is full" << std::endl;
        return;
    }

    back = (back+1) % size;
    arr[back] = aSong;
    count++;
}

// Time complexity O(1). Space complexity O(1)
template<typename T>
T* TQueue<T>::Dequeue() {
    if (IsEmpty()) {
        std::cout << "Queue is already empty" << std::endl;
        return nullptr;
    }

    T* song = arr[front];
    front = (front+1) % size;
    count--;
    return song;
}

template<typename T>
bool TQueue<T>::IsEmpty() const {
    return count == 0;
}

template<typename T>
T* TQueue<T>::Peek() {
    if (IsEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return nullptr;
    }
    return arr[front];
}

template<typename T>
T* TQueue<T>::PlayNextSong() {
    // If the wish queue has data dequeue from the wishlist
    if (!WishQueue->IsEmpty()) {
        TSong* song = WishQueue->Dequeue();
        HistoryStack->Push(song);
        return song;
    }
    // If the wishlist is empty play from the main queue
    TSong* song = MainQueue->Dequeue();
    HistoryStack->Push(song);
    return song;
}

template<typename T>
void TQueue<T>::FrontOfQueue(T *aSong) {
    if (count == size - 1) {
        std::cout << "Queue is full" << std::endl;
        return;
    }
    front = (front-1 + size) % size;
    arr[front] = aSong;
    count++;
}

template class TQueue<TSong>;

