#include "TGraph.h"

#include <limits>
#include <unordered_map>
#include <unordered_set>

#include "TMinHeap.h"

TGraph::TGraph(const bool aIsDirected, const bool aIsWeighted)  : graph(true), isDirected(aIsDirected), isWeighted(aIsWeighted){};

TGraph::~TGraph() {
    auto* temp = graph.GetHead()->GetNextPtr();

    while (temp != graph.GetTail()) {
        const TVertex* vertex = *(temp->GetData());
        delete vertex; // TVertex destructor cleans up edges
        temp = temp->GetNextPtr();
    }
}

void TGraph::AddVertex(TVertex *aVertex) {
    auto** store = new TVertex*(aVertex); // Creates a new TVertex object
    graph.Append(store); // Save in list
}

void TGraph::AddEdge(TVertex *aVertex1, TVertex *aVertex2, const int weight) const {

    auto *forward = new TEdge(aVertex1, aVertex2, weight); // Adds edge from vertex1 to vertex 2
    aVertex1->AddEdge(forward);
    if (!isDirected) {
        // Considering all graphs in our option is undirected this will always be true, but we do this to keep it dynamic
        auto *reverse = new TEdge(aVertex2, aVertex1, weight);
        aVertex2->AddEdge(reverse);
    }
}

bool TGraph::HasEdge(TVertex *aVertex1, const TVertex *aVertex2) {
    for (int i = 0; i < aVertex1->GetEdgeCount(); i++) {
        if (aVertex1->GetEdges()[i]->GetTo() == aVertex2) { // If vertex1 has an edge which goes to vertex 2
            return true;
        }
    }
    return false;
}

DijkstraResult TGraph::Dijkstra(TVertex* aStart, TVertex* aGoal)
{
    // Distances, previous, visited
    std::unordered_map<TVertex*, int> distance;
    std::unordered_map<TVertex*, TVertex*> previous;
    std::unordered_set<TVertex*> visited;

    // Initialize all vertices
    for (auto* node = graph.GetHead()->GetNextPtr();
         node != graph.GetTail();
         node = node->GetNextPtr())
    {
        TVertex* vertex = *(node->GetData());
        distance[vertex] = std::numeric_limits<int>::max();
        previous[vertex] = nullptr;
    }

    distance[aStart] = 0;

    // Min-heap priority queue
    TMinHeap minHeap;
    minHeap.Add(THeapNode(aStart, 0));

    // Dijkstra main loop
    while (!minHeap.IsEmpty())
    {
        THeapNode hn = minHeap.ExtractMin();
        TVertex* current = hn.GetVertex();

        if (visited.count(current))
            continue;

        visited.insert(current);

        if (current == aGoal)
            break;

        for (int i = 0; i < current->GetEdgeCount(); i++)
        {
            const TEdge* edge = current->GetEdges()[i];
            TVertex* neighbor = edge->GetTo();
            const int weight = edge->GetWeight();

            const int currentDist = distance[current];
            if (currentDist == std::numeric_limits<int>::max())
                continue;

            if (const int newDist = currentDist + weight; newDist < distance[neighbor])
            {
                distance[neighbor] = newDist;
                previous[neighbor] = current;
                minHeap.Add(THeapNode(neighbor, newDist));
            }
        }
    }

    TVertex* curr = aGoal;
    auto* path = new TStack<TVertex>(500, false); // For this to not leak memory, we MUST delete it in the function caller

    while (curr != nullptr)
    {
        path->Push(curr);
        curr = previous[curr];
    }

    return DijkstraResult{ path, distance[aGoal] };

}

