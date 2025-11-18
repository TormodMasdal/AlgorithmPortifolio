#include "option1.h"

#include <iostream>
#include <random>

#include "SharedLib.h"
#include "TEmployee.h"
#include "TBST.hpp"
#include "TAVLTree.hpp"

TBST<int, TEmployee> bst;
TAVLTree<int, TEmployee> avlTree;

int totalAccountsCreated = 0;
int maxAccounts = 200;


// Function for generating employees
static bool GenerateEmployee(const int aIndex, const int aTotal, const std::string& aFirstName, const std::string& aLastName) {
	if (totalAccountsCreated >= maxAccounts) return false;

	TEmployee newEmployee(aFirstName, aLastName);
	bst.insert(newEmployee.getEmployeeID(), newEmployee);
	avlTree.insert(newEmployee.getEmployeeID(), newEmployee);
	totalAccountsCreated++;

	return true;
}

void displayMenu() {
	std::cout << "\n========== Menu ==========\n";
	std::cout << "\n===== BST =====\n";
	std::cout << "1. insert\n";
	std::cout << "2. Perform Action 2\n";
	std::cout << "3. Perform Action 3\n";
	std::cout << "4. Exit\n";
	std::cout << "Enter your choice: ";
}

int RunApp() {
	std::string file = "C:\\Users\\jakub\\203Exam\\IKT203\\DATA\\random_names.txt";
	readNamesFromFile(file, GenerateEmployee);

	int choice = 0;

	while (true) {
		displayMenu();
		std::cin >> choice;
		switch (choice) {
			case 1:
				avlTree.printLevelOrder();
				break;
			case 2:
				int key;
				std::cin >> key;
				avlTree.remove(key);
				break;
		}
	}




	return 0;
}
