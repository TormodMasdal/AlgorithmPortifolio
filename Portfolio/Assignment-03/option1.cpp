#include "option1.h"
#include "SharedLib.h"

#include "TEmployee.h"
#include "TBST.hpp"
#include "TAVLTree.hpp"
#include "Menu.h"

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

int RunApp() {
	std::string file = "DATA/random_names.txt";
	readNamesFromFile(file, GenerateEmployee);

	// Interactive UI where user gets presented with different choices to perform different operations on BST/AVLTree
	menu(bst, avlTree);
	return 0;


}
