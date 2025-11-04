#include "TNode.h"
#include "TSong.h"

// Constructor, initialize the data, and sets next and prev to nullptr
template<typename T>
TNode<T>::TNode(T* aData) : data(aData), next(nullptr), prev(nullptr) {}

template<typename T>
TNode<T>::~TNode() {
    // Sets all to nullptr to avoid dangling pointers
    data = nullptr; // Don't delete data, may exist outside the list
    next = nullptr;
    prev = nullptr;
}

template<typename T>
void TNode<T>::SetNext(TNode *aNextNode) {
    next = aNextNode;
}

template<typename T>
void TNode<T>::SetPrev(TNode *aPrevNode) {
    prev = aPrevNode;
}

template<typename T>
T *TNode<T>::GetData() {
    return data;
}

template<typename T>
TNode<T> *TNode<T>::GetNextPtr() {
    return next;
}

template<typename T>
TNode<T> *TNode<T>::GetPrevPtr() {
    return prev;
}

template class TNode<TSong>;


