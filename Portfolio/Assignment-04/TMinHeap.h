#ifndef MINHEAP_H
#define MINHEAP_H
#include <SharedLib.h>

class TMinHeap {
public:
    void Add(const std::pair<std::string, int>& aItem);
    std::pair<std::string, int> ExtractMin();
    bool Empty() const;
    size_t Size() const;

private:
    std::vector<std::pair<std::string, int>> minHeap;
};



#endif //MINHEAP_H
