#ifndef TEDGE_H
#define TEDGE_H
#include "TVertex.h"

class TVertex; // Forward declaration

class TEdge {
public:
    TEdge(TVertex* aFrom, TVertex* aTo, int aWeight); // Constructor

    // Getters
    [[nodiscard]] TVertex* GetTo() const;
    [[nodiscard]] TVertex* GetFrom() const;
    [[nodiscard]] int GetWeight() const;

private:
    // Private attributes for edges
    TVertex* from;
    TVertex* to;
    int weight;
};



#endif //TEDGE_H
