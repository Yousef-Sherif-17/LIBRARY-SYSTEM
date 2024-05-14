#include "Employee.h"

Employee::Employee(string name, int age, double salary) {

    this->name = name;
    this->age = age;
    this->salary = salary;
}

string Employee::getName() {

        return name;
}

int Employee::getAge() {

    return age;
}

double Employee::getSalary() {

    return salary;
}

