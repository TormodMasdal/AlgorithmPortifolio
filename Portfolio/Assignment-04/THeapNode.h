#ifndef THEAPNODE_H
#define THEAPNODE_H
#include "TVertex.h"


class THeapNode {
public:
    explicit THeapNode(TVertex* aVertex = nullptr, int aDistance = 0); // Default constructor

    // Getters
    TVertex* GetVertex() const;
    int GetDistance() const;
private:
    TVertex* vertex;
    int distance;
};



#endif //THEAPNODE_H
