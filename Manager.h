#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

class Manager {

private:

    int employeesNum = 2;
    Employee* employees = new Employee[employeesNum];

public:

    Manager();

    void managerPage();

    void showEmployees();
    
    void hire();

    void fire();
    
};

