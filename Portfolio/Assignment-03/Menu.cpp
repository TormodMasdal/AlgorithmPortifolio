#include "Menu.h"

#include <iostream>

void menu(TBST<int, TEmployee*> &bst, TAVLTree<int, TEmployee*> &avlTree) {
    int choice = 0;

	while (true) {

		std::cout << "\n===== BST/AVLTree =====\n";
		std::cout << " 1. BST insert\n";
		std::cout << " 2. BST remove\n";
		std::cout << " 3. BST search\n";
		std::cout << " 4. AVLTree insert\n";
		std::cout << " 5. AVLTree remove\n";
		std::cout << " 6. AVLTree search\n";
		std::cout << "\n===== Traversals =====\n";
		std::cout << " 7. Inorder\n";
		std::cout << " 8. Preorder\n";
		std::cout << " 9. Postorder\n";
		std::cout << " 10. Level Order\n";
		std::cout << "" << std::endl;
		std::cout << " 11. Exit\n";
		std::cout << "Enter your choice (1-9): \n";

		std::cin >> choice;

		switch (choice) {
			case 1: {
				std::string firstName;
				std::string lastName;

				std::cout << "Enter the first name for the employee you want to insert : \n";
				std::cin >> firstName;
				std::cout << "Enter the last name for the employee you want to insert : \n";
				std::cin >> lastName;

				auto* newEmployee = new TEmployee(firstName, lastName);
				bst.insert(newEmployee->getEmployeeID(), newEmployee);
				std::cout << "Inserted employee with ID: " << newEmployee->getEmployeeID() << std::endl;
				break;
			}
			case 2: {
				int keyToRemove = 0;
				std::cout << "Enter the key for the employee you want to remove : \n";
				std::cin >> keyToRemove;
				bst.remove(keyToRemove);
				break;
			}
			case 3: {
				int keyToSearch = 0;
				std::cout << "Enter the key for the employee you want to search for : \n";
				std::cin >> keyToSearch;

				if (bst.search(keyToSearch)) {
					std::cout << "Employee with key " << keyToSearch << " was found thats\n";
				}
				else {
					std::cout << "Employee with key " << keyToSearch << " wasn't found!\n";
				}
				break;
			}
			case 4: {
				std::string firstName;
				std::string lastName;

				std::cout << "Enter the first name for the employee you want to insert : \n";
				std::cin >> firstName;
				std::cout << "Enter the last name for the employee you want to insert : \n";
				std::cin >> lastName;

				auto* newEmployee = new TEmployee(firstName, lastName);
				avlTree.insert(newEmployee->getEmployeeID(), newEmployee);
				std::cout << "Inserted employee with ID: " << newEmployee->getEmployeeID() << std::endl;
				break;
			}
			case 5: {
				int keyToRemove = 0;
				std::cout << "Enter the key for the employee you want to remove : \n";
				std::cin >> keyToRemove;
				avlTree.remove(keyToRemove);
				break;
			}
			case 6: {
				int keyToSearch = 0;
				std::cout << "Enter the key for the employee you want to search for : \n";
				std::cin >> keyToSearch;

				if (avlTree.search(keyToSearch)) {
					std::cout << "Employee with key " << keyToSearch << " was found!\n";
				}
				else {
					std::cout << "Employee with key " << keyToSearch << " wasn't found!\n";
				}
				break;
			}
			case 7: {
				int treeToTraverse = 0;
				std::cout << "1. BST\n";
				std::cout << "2. AVLTree\n";
				std::cout << "Enter your choice for what tree you want to traverse (Inorder): \n";
				std::cin >> treeToTraverse;
				if (treeToTraverse == 1) {
					bst.printInorder();
				}
				else if (treeToTraverse == 2) {
					avlTree.printInorder();
				}
				else {
					std::cout << "Enter a valid choice!\n";
				}
				break;
			}
			case 8: {
				int treeToTraverse = 0;
				std::cout << "1. BST\n";
				std::cout << "2. AVLTree\n";
				std::cout << "Enter your choice for what tree you want to traverse (Preorder): \n";
				std::cin >> treeToTraverse;
				if (treeToTraverse == 1) {
					bst.printPreorder();
				}
				else if (treeToTraverse == 2) {
					avlTree.printPreorder();
				}
				else {
					std::cout << "Enter a valid choice! \n";
				}
				break;
			}
			case 9: {
				int treeToTraverse = 0;
				std::cout << "1. BST\n";
				std::cout << "2. AVLTree\n";
				std::cout << "Enter your choice for what tree you want to traverse (Postorder): \n";
				std::cin >> treeToTraverse;
				if (treeToTraverse == 1) {
					bst.printPostorder();
				}
				else if (treeToTraverse == 2) {
					avlTree.printPostorder();
				}
				else {
					std::cout << "Enter a valid choice! \n";
				}
				break;
			}
			case 10: {
				int treeToTraverse = 0;
				std::cout << "1. BST\n";
				std::cout << "2. AVLTree\n";
				std::cout << "Enter your choice for what tree you want to traverse (Level Order): \n";
				std::cin >> treeToTraverse;
				if (treeToTraverse == 1) {
					bst.printLevelOrder();
				}
				else if (treeToTraverse == 2) {
					avlTree.printLevelOrder();
				}
				else {
					std::cout << "Enter a valid choice! \n";
				}
				break;
			}
			case 11:
				return;
			default:
				std::cout << "Wrong choice!\n";
		}
	}
}