#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

class Company {

private:
    Employee* employees[4];
    int numEmployees;

public:



    Company();

    void hire(string name, int age, double salary);
    

    void fire();
   

    void showEmployees();
   

    void hireNewEmployee();
    
};


    /*
    void hireMenu() {
        string name;
        int age;
        double salary;

        cout << "Enter the name of the employee: ";
        cin >> name;
        cout << "Enter the age of the employee: ";
        cin >> age;
        cout << "Enter the salary of the employee: ";
        cin >> salary;

        hire(name, age, salary);
    }
    */