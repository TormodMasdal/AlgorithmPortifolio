#ifndef MINHEAP_H
#define MINHEAP_H
#include "THeapNode.h"

class TMinHeap {
public:
    TMinHeap(); // Constructor

    bool IsEmpty() const;
    void Add(const THeapNode& aItem);
    THeapNode ExtractMin();

private:
    int size;
    THeapNode heap[500];

    // Private helper functions
    int Parent(int i);
    int Left(int i);
    int Right(int i);

    bool Compare(THeapNode& a, THeapNode& b);

    void HeapifyUp(int i);
    void HeapifyDown(int i);
};



#endif //MINHEAP_H
