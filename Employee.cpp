#include "Employee.h"

Employee::Employee() {

	Employee::


}

Employee::Employee(string name, int age, double salary) {
	setName(name);
	setAge(age);
	setSalary(salary);
}

// Setters
void Employee::setName(string name) {
	this->name = name;
}
void Employee::setAge(int age) {
	this->age = age;
}
void Employee::setSalary(double salary) {
	this->salary = salary;
}

// Getters
string Employee::getName() {
	return name;
}
int Employee::getAge() {
	return age;
}
double Employee::getSalary() {
	return salary;
}

