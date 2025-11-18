#include "TEdge.h"

TEdge::TEdge(TVertex *aFrom, TVertex *aTo, const int aWeight)
    : from(aFrom), to(aTo), weight(aWeight) {}

TVertex *TEdge::GetFrom() const {
    return from;
}

TVertex *TEdge::GetTo() const {
    return to;
}

int TEdge::GetWeight() const {
    return weight;
}


