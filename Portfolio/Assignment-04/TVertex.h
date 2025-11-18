#ifndef TVERTEX_H
#define TVERTEX_H

#include "iostream"
#include "TEdge.h"

class TEdge; // Forward declaration

class TVertex {
public:
    explicit TVertex(std::string aVertex); // Constructor
    ~TVertex(); // Destructor

    void AddEdge(TEdge* aEdge);
    void RemoveEdgeTo(const TVertex* aTarget);
    int GetEdgeCount() const;
    TEdge** GetEdges();
    std::string GetName();
private:
    std::string vertex;
    TEdge* edges[50];
    int edgeCount;
};



#endif //TVERTEX_H
