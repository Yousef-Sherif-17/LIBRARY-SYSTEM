#pragma once
#include "Employee.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Manager 
{
private:

	static vector<Employee> employees;

public:
  
	Manager();

  void managerPage();

  void showEmployees();

  void hire();

  void updateEmployeeData();

  void fire();
};