#pragma once
#include "Client.h"
#include <string>
#include <iostream>

class Librarian 
{
private:



public:
	Librarian() {


	}

};

class Employee
{
private:
	std::string name;
	int age;
	double salary;

	std::string employeeInfo[5]{
		
	};

public:
	Employee() 
	{
		std::cout << "================================================\n";
		std::cout << "1. Hire an employee.        2. Fire an employee.\n";
		std::cout << "================================================\n";
		
		int Ifhire;
		std::cin >> Ifhire;

		switch (Ifhire == 1)
		{
		case 1:

			std::cout << "Enter The Employee Name: ";
			std::string Name;
			std::cin >> Name;
			name = Name;
			std::cout << "Enter The Employee Age: ";
			int Age;
			std::cin >> Age;
			age = Age;
			std::cout << "Enter The Employee Salary: ";
			double Salary;
			std::cin >> Salary;
			salary = Salary;
			std::cout << "================================================\n";
			break;
		
		}
	}
	
};




