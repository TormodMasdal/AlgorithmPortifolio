#include "option1.h"
#include <iostream>
#include <limits>
#include <utility>
#include "TMinHeap.h"

#include "SharedLib.h"

// Every node may be connected to multiple other nodes, therefore a vector, and every edge has a weight, therefore the int
// This is a very long type which will be used multiple times, therefore give it a shorter name: GraphType
using GraphType = std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>;

// Unordered map for adjacency list
GraphType adjacencyList;

static bool NodeReadCallback(const int aIndex, const int aTotalCount, const std::string& aNode) {

	// Initializes key in the adjacencyList
	adjacencyList[aNode];

	// Return true to continue reading
	return true;
}

static bool EdgeReadCallback(const int aIndex, const int aTotalCount, const std::string& aFromNode, const std::string& aToNode, float aWeight)
{
	// Adds the weight and node that's connected to the from node
	adjacencyList[aFromNode].emplace_back(aToNode, aWeight);

	// Because the graph is undirected, and edge from A to B also means we must add an edge from B to A
	adjacencyList[aToNode].emplace_back(aFromNode, aWeight);

	// Return true to continue reading
	return true;
}

void DijkstrasAlgorithm(const GraphType& aGraph, const std::string& aSource, const std::string& aGoal) {

	std::unordered_map<std::string, int> distances; // Saves shortest distance to
	std::unordered_map<std::string, std::string> predecessors;

	for (const auto& [node, _] : aGraph) {
		distances[node] = std::numeric_limits<int>::max();
		predecessors[node] = "";
	}
	distances[aSource] = 0;

	TMinHeap minHeap;
	minHeap.Add({aSource, 0}); // Adds the source to the minheap, giving it length of 0


	while (minHeap.Size() != 0) {
		auto [currentNode, currentDist] = minHeap.ExtractMin();

		if (currentDist > distances[currentNode]) continue;
		if (currentNode == aGoal) break;

		for (const auto& [neighbor, weight] : aGraph.at(currentNode)) {
			int newDist = currentDist + weight;
			if (newDist < distances[neighbor]) {
				distances[neighbor] = newDist;
				predecessors[neighbor] = currentNode;
				minHeap.Add({neighbor, newDist});
			}
		}
	}

	// Rekonstruer korteste vei
	std::vector<std::string> path;
	for (std::string at = aGoal; at != ""; at = predecessors[at]) {
		path.push_back(at);
	}
	std::reverse(path.begin(), path.end());

	std::cout << "Lowest latency path: ";
	for (const auto& node : path) {
		std::cout << node << " -> ";
	}
	std::cout << "(Total: " << distances[aGoal] << "ms)" << std::endl;
}




int RunApp() {
	// Path to the graph data file
	std::string filename = "C:/Users/tormo/IKT203Exam/IKT203Exam/DATA/network_graph.txt";

	readGraphFromFile(filename, NodeReadCallback, EdgeReadCallback);

	DijkstrasAlgorithm(adjacencyList, "WebServer", "Database");
	return 0;
}
