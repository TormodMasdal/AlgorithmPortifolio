#include "option1.h"

#include <iostream>

#include "TEmployee.h"
#include "TBST.hpp"

int RunApp() {
	//readNamesFromFile("C:\\Users\\jakub\\203Exam\\IKT203\\DATA\\random_names.txt", NameReadCallback);

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


	TBST<int, TEmployee> tree;
	tree.insert(employee.employeeID, employee);
	tree.insert(employee2.employeeID, employee2);
	tree.insert(employee3.employeeID, employee3);
	tree.insert(employee4.employeeID, employee4);

	//tree.remove(1);

	if (tree.search(5)) {
		std::cout << "Node is found" << std::endl;
	}
	else {
		std::cout << "Node is not found"<< std::endl;
	}
	return 0;

}