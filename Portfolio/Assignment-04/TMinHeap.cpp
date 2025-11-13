#include "TMinHeap.h"

void TMinHeap::Add(const std::pair<std::string, int>& aItem) {
    minHeap.push_back(aItem); // Push the new item to the back of the list
    size_t i = minHeap.size() - 1; // Starts iterating from the index at the back

    while (i > 0) { // While we are not at the root node
        size_t parent = (i - 1) / 2; // Using "Tree" trick to get parent node
        if (minHeap[i].second < minHeap[parent].second) { // If the cost of i is cheaper than its parent, swap them
            auto temp = minHeap[i];
            minHeap[i] = minHeap[parent];
            minHeap[parent] = temp;
            i = parent;
        } else { // If no swap, then break
            break;
        }
    }
}

std::pair<std::string, int> TMinHeap::ExtractMin() { // Returns the lowest path
    if (minHeap.empty()) return {"", -1};

    auto extract = minHeap[0]; // Saves the lowest path, so we can return later
    minHeap[0] = minHeap[minHeap.size() - 1]; // Sets the new lowest value to the one all the way in the back of the list
    minHeap.pop_back(); // To avoid duplicates we can now remove the last item in the list

    size_t i = 0;
    while (true) {

        // Uses "Tree" trick to get child nodes
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;
        size_t smallest = i;

        if (left < minHeap.size() && minHeap[left].second < minHeap[smallest].second) // If the left child exist, and its smaller than the parent node, change the smallest element
            smallest = left;
        if (right < minHeap.size() && minHeap[right].second < minHeap[smallest].second) // If the right child exist, and its smaller than the lowest node, change the smallest element
            smallest = right;
        if (smallest == i) break; // If the value hasn't changed, it is in correct position. Break.

        // Swap the lowest element with the earlier one
        auto temp = minHeap[i];
        minHeap[i] = minHeap[smallest];
        minHeap[smallest] = temp;
        i = smallest;
    }

    // Return the variabel we created earlier
    return extract;
}

bool TMinHeap::Empty() const {
    return minHeap.empty();
}

size_t TMinHeap::Size() const {
    return minHeap.size();
}


