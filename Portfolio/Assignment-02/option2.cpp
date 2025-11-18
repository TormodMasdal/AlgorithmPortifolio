#include "option2.h"

#include <iostream>

#include "include/TTestSuite.h"

int RunApp() {
	std::cout << "Running TestSuite\n";
	TTestSuite::RunAll();
	return 0;
}