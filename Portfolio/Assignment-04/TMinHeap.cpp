#include "TMinHeap.h"

TMinHeap::TMinHeap() : size(0) {

}

bool TMinHeap::IsEmpty() const {
    return size == 0;
}

void TMinHeap::Add(const THeapNode &aItem) {
    if (size + 1 >= 500) return; // If heap is full, return

    heap[++size] = aItem; // Increment size of heap, and add item to it
    HeapifyUp(size); // Calls HepifyUp function from the last item, so it remains as a min-heap
}

THeapNode TMinHeap::ExtractMin() {
    if (size == 0) return THeapNode(nullptr, -1); // Invalid if no item is in the heap

    THeapNode root = heap[1]; // Root is always at pos 1 in a 1-based index (required for Tree "trick" in array)
    heap[1] = heap[size]; // Push the vertex in the back of the heap to the root node
    size--; // The heap will have 1 less item

    HeapifyDown(1); // Calls heapifydown to get the new root element to correct position
    return root;
}

int TMinHeap::Parent(int i) { // Tree trick
    return i / 2;
}

int TMinHeap::Left(int i) {
    return i * 2;
}

int TMinHeap::Right(int i) {
    return i * 2 + 1;
}

bool TMinHeap::Compare(THeapNode &a, THeapNode &b) { // Compare distance of two edges
    return a.GetDistance() < b.GetDistance();
}

// Crucial for keeping the min heap sorted
// As long as the child is smaller than the parent, bubble up
void TMinHeap::HeapifyUp(int i) {
    while (i > 1 && Compare(heap[i], heap[Parent(i)])) {
        THeapNode temp = heap[i];
        heap[i] = heap[Parent(i)];
        heap[Parent(i)] = temp;

        i = Parent(i);
    }
}

// Crucial for keeping the min heap sorted
void TMinHeap::HeapifyDown(int i) {
    while (true)
    {
        int left = Left(i);
        int right = Right(i);
        int smallest = i;

        if (left <= size && Compare(heap[left], heap[smallest]))
            smallest = left; // Left child is smaller than current smallest

        if (right <= size && Compare(heap[right], heap[smallest]))
            smallest = right; // Right child is smaller than current smallest

        if (smallest == i) // If smallest hasn't changed, break out the loop
            break;

        // Swap
        THeapNode temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }
}













