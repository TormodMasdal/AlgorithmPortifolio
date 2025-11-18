#include "option1.h"

#include <map>

#include "TGraph.h"

#include "SharedLib.h"


TGraph graph(false, true);
std::map<std::string, TVertex*> lookup;

static bool NodeReadCallback(const int aIndex, const int aTotalCount, const std::string& aNode) {

	TVertex* vertex = new TVertex(aNode);

	graph.AddVertex(vertex);

	lookup[aNode] = vertex;

	// Return true to continue reading
	return true;
}

static bool EdgeReadCallback(const int aIndex, const int aTotalCount, const std::string& aFromNode, const std::string& aToNode, float aWeight)
{
	TVertex* from = lookup[aFromNode];
	TVertex* to = lookup[aToNode];

	graph.AddEdge(from, to, static_cast<int>(aWeight));

	// Return true to continue reading
	return true;
}


int RunApp() {
	// Path to the graph data file
	std::string filename = "C:/Users/tormo/IKT203Exam/IKT203Exam/DATA/network_graph.txt";

	readGraphFromFile(filename, NodeReadCallback, EdgeReadCallback);

	int choice = 0;
	while (true) {
		std::cout << "\n1. Find lowest latency path" << std::endl;
		std::cout << "2. Exit" << std::endl;
		std::cout << "Enter a choice: " << std::endl;
		std::cin >> choice;
		switch (choice) {

			case 1: {
				std::string from, to;
				std::cout << "Enter source server: ";
				std::cin >> from;

				std::cout << "Enter Destination server: ";
				std::cin >> to;

				if (!lookup.count(from) || !lookup.count(to)) {
					std::cout << "Invalid server name!\n";
					return 0;
				}

				std::cout << "Lowest latency path from: "
			  << from
			  << " to: "
			  << to
			  << ":\n";

				auto result = graph.Dijkstra(lookup[from], lookup[to]);

				TStack<TVertex>* path = result.path;

				for (int i = path->GetItemAmount()-1; i >= 0; i--) {
					TVertex* v = path->Pop();
					std::cout << v->GetName();
					if (i >= 1) std::cout << " -> ";
				}
				delete path; // Delete so no leaked memory


				std::cout << "\n(Total: " << result.totalDistance << "ms)\n";

				break;
			}
			case 3: return 0;
			default: std::cout << "Invalid input" << std::endl;
		}
	}
}
