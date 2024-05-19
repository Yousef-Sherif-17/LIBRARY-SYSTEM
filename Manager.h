#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"

using namespace std;

class Manager {

private:

    static vector <Employee> employees;

public:

    Manager();

    void managerPage();

    void showEmployees();
    
    void hire();

    void updateEmployeeData();

    void fire();
    
};

