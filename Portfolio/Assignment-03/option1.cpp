#include "option1.h"
#include "SharedLib.h"

#include "TEmployee.h"
#include "TBST.hpp"
#include "TAVLTree.hpp"
#include "Menu.h"

TBST<int, TEmployee*> bst;
TAVLTree<int, TEmployee*> avlTree;

int totalAccountsCreated = 0;
int maxAccounts = 200;

// Function for generating employees
static bool GenerateEmployee(const int aIndex, const int aTotal, const std::string& aFirstName, const std::string& aLastName) {
	if (totalAccountsCreated >= maxAccounts) return false;

	// Create one employee and duplicate it so each tree owns its own copy.
	// This allows deleting from one tree without affecting the other.
	auto* empBST = new TEmployee(aFirstName, aLastName);
	auto* empAVL = new TEmployee(*empBST); // Copy

	int id = empBST->getEmployeeID();

	bst.insert(id, empBST);
	avlTree.insert(id, empAVL);

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
