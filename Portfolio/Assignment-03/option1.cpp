#include "option1.h"

#include <iostream>

#include "TEmployee.h"
#include "TBST.hpp"
#include "TAVLTree.hpp"
#include "TAVLTreeNode.hpp"


int RunApp() {
	//readNamesFromFile("C:\\Users\\jakub\\203Exam\\IKT203\\DATA\\random_names.txt", NameReadCallback);

	TBST<int, TEmployee> bstTree;
	TAVLTree<int, TEmployee> avlTree;

	TEmployee employee;
	employee.employeeID = 1;
	employee.firstName = "John";
	employee.lastName = "Doe";

	TEmployee employee2;
	employee2.employeeID = 6;
	employee2.firstName = "John";
	employee2.lastName = "Doe";

	TEmployee employee3;
	employee3.employeeID = 8;
	employee3.firstName = "John";
	employee3.lastName = "Doe";

	TEmployee employee4;
	employee4.employeeID = 7;
	employee4.firstName = "John";
	employee4.lastName = "Doe";

	bstTree.insert(employee.employeeID, employee);
	bstTree.insert(employee2.employeeID, employee2);
	bstTree.insert(employee3.employeeID, employee3);
	bstTree.insert(employee4.employeeID, employee4);

	if (bstTree.search(8)) {
		std::cout << "Node is found" << std::endl;
	}
	else {
		std::cout << "Node is not found"<< std::endl;
	}

	avlTree.insert(employee.employeeID, employee);
	avlTree.insert(employee2.employeeID, employee2);
	avlTree.insert(employee3.employeeID, employee3);
	avlTree.insert(employee4.employeeID, employee4);

	bstTree.printLevelOrder();

	return 0;
}
