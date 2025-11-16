#ifndef IKT203_COURSE_ASSIGNMENTS_TEMPLOYEE_H
#define IKT203_COURSE_ASSIGNMENTS_TEMPLOYEE_H
#include <random>
#include <string>

class TEmployee {
private:
    int employeeID;

public:
    std::string firstName;
    std::string lastName;

    TEmployee(std::string firstName, std::string lastName);

    int getEmployeeID();
};


#endif //IKT203_COURSE_ASSIGNMENTS_TEMPLOYEE_H