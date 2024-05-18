#include "Manager.h"

Company::Company() {

    numEmployees = 0;
    
}

void Company::hire(string name, int age, double salary)
{
    if (numEmployees < 4)
    {
        employees[numEmployees] = new Employee(name, age, salary);
        numEmployees++;

        cout << "     1.Hire                   2.Fire     \n";
        cout << "     3.Show Employees         4.Back     \n";
        int choice;
        cin >> choice;

        switch (choice)
        {

        case 1:
            hireNewEmployee();
            break;
        case 2:
            fire();
            break;
        case 3:
            showEmployees();
            break;
        case 4:
            //HomePage();
        default:
            break;
        }
    }


}

void Company::fire()
{

    showEmployees();
    int choice;
    cout << "Enter the index of the employee you want to fire: ";
    cin >> choice;
    if (choice >= 0 && choice < numEmployees)
    {
        delete employees[choice];
        for (int i = choice; i < numEmployees - 1; ++i)
        {
            employees[i] = employees[i + 1];
        }
        numEmployees--;
        cout << "Employee successfully fired.\n";
    }
    else {
        cout << "Invalid index.\n";
    }
}

void Company::showEmployees()
{

    cout << "Employees:\n";
    for (int i = 0; i < numEmployees; ++i)
    {

        cout << i << ". Name: " << employees[i]->getName() << ", Age: " << employees[i]->getAge() << ", Salary: " << employees[i]->getSalary() << "\n";
    }
}

void Company::hireNewEmployee()
{

    string name;
    int age;
    double salary;

    cout << "Enter the name of the new employee: ";
    cin >> name;
    cout << "Enter the age of the new employee: ";
    cin >> age;
    cout << "Enter the salary of the new employee: ";
    cin >> salary;

    hire(name, age, salary);
}
