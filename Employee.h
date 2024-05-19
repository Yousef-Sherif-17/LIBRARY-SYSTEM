#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int age;
    double salary;

public:
    Employee();
    Employee(string name, int age, double salary);

    void setName(string name);
    void setAge(int age);
    void setSalary(double salary);

    string getName();
    int getAge();
    double getSalary();
};

