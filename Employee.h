#include <iostream>
#include <string>

using namespace std;

class Employee {

private:
    string name;
    int age;
    double salary;

public:

    // Cosntructors
    Employee();
    Employee(string name, int age, double salary);

    // Setters
    void setName(string name);
    void setAge(int age);
    void setSalary(double salary);

    // Getters
    string getName();
    int getAge();
    double getSalary();

};

