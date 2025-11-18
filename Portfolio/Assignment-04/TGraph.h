#ifndef TGRAPH_H
#define TGRAPH_H
#include "TLinkedList.hpp"
#include "TStack.hpp"
#include "TVertex.h"

struct DijkstraResult {
    TStack<TVertex>* path;
    int totalDistance;
};

class TGraph {
public:
    TGraph(bool aIsDirected, bool aIsWeighted); // Constructor
    ~TGraph(); // Destructor

    void AddVertex(TVertex* aVertex);
    void AddEdge(TVertex* aVertex1, TVertex* aVertex2, int weight) const;

    static bool HasEdge(TVertex* aVertex1, const TVertex* aVertex2);

    DijkstraResult Dijkstra(TVertex* aStart, TVertex* aGoal);


private:
    TLinkedList<TVertex*> graph; // Graph stored in a linked list
    bool isDirected;
    bool isWeighted;
};





#endif //TGRAPH_H
