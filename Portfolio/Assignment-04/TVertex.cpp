#include "TVertex.h"

TVertex::TVertex(std::string aVertex) : vertex(std::move(aVertex)) {
    for (int i = 0; i < 50; i++) { // Initialize all edge pointers to nullptr (avoid garbage pointers)
        edges[i] = nullptr;
    }
    edgeCount = 0;
}

TVertex::~TVertex() {
    // Delete all edges this vertex owns
    for (int i = 0; i < edgeCount; i++) {
        delete edges[i];
        edges[i] = nullptr;
    }
}


void TVertex::AddEdge(TEdge *aEdge) {
    if (edgeCount >= 50) return; // To many edges
    edges[edgeCount++] = aEdge; // Add edge to index, then increment the count
}

void TVertex::RemoveEdgeTo(const TVertex *aTarget) {
    for (int i = 0; i < edgeCount; i++) { // Iterate until we find target
        if (edges[i] != nullptr && edges[i]->GetTo() == aTarget) { // If we find target at specific index, delete edge at that index
            delete edges[i];

            edges[i] = edges[edgeCount -1]; // Move last element to the new "Hole" in the list
            edges[edgeCount -1] = nullptr; // Change the now moved previous position to nullptr

            edgeCount--; // Reduce count of the list
            return;
        }
    }
}

// Getters
TEdge **TVertex::GetEdges() {
    return edges;
}

int TVertex::GetEdgeCount() const {
    return edgeCount;
}

std::string TVertex::GetName() {
    return vertex;
}








