#include "THeapNode.h"

THeapNode::THeapNode(TVertex *aVertex, const int aDistance) : vertex(aVertex), distance(aDistance) {}

int THeapNode::GetDistance() const {
    return distance;
}

TVertex *THeapNode::GetVertex() const {
    return vertex;
}

