#include "TEmployee.h"

#include "GenerateEmployeeID.h"

TEmployee::TEmployee(std::string firstName, std::string lastName) : firstName(firstName), lastName(lastName) {
    employeeID = GenerateEmployeeID();
}

int TEmployee::getEmployeeID() {
    return employeeID;
}