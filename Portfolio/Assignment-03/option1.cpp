#include "option1.h"

#include <iostream>
#include <random>

#include "SharedLib.h"
#include "TEmployee.h"
#include "TBST.hpp"
#include "TAVLTree.hpp"

TBST<int, TEmployee> bstTree;
TAVLTree<int, TEmployee> avlTree;

// Function for generating employees
static bool GenerateEmployee(const int aIndex, const int aTotal, const std::string& aFirstName, const std::string& aLastName) {
	TEmployee newEmployee(aFirstName, aLastName);
	avlTree.insert(newEmployee.getEmployeeID(), newEmployee);
	return true;
}

int RunApp() {
	std::string file = "C:\\Users\\jakub\\203Exam\\IKT203\\DATA\\random_names.txt";
	readNamesFromFile(file, GenerateEmployee);

	if (avlTree.search(10000)) {
		std::cout << "Node is found" << std::endl;
	}
	else {
		std::cout << "Node is not found"<< std::endl;
	}

	avlTree.printLevelOrder();

	avlTree.remove(12);
	avlTree.printLevelOrder();


	return 0;
}
