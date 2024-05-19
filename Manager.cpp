#include "Manager.h"
#include "Customer.h"
#include "Employee.h"

Manager::Manager() {

    managerPage();

}

void Manager::managerPage()
{



    if (employeesNum <= 4)
    {
        cout << "     1.Show Employees                   2.Hire\n";
        cout << "     3.Fire                             4.Back\n";

        int choice;
        do
        {
            cin >> choice;
            switch (choice)
            {
            case 1:
                showEmployees();
                break;
            case 2:
                hire();
                break;
            case 3:
                fire();
                break;
            case 4:
                Customer::mainMenu();
                break;
            default:
                cout << "\nInvalid Input!\n";
                cout << "Choose a number between (1-4): ";
                break;
            }
        } while (choice < 1 || choice >  4);
    }
    else {
        cout << "     1.Show Employees                   2.Fire\n";
        cout << "     3.Back\n";

        int choice;
        do
        {
            cin >> choice;
            switch (choice)
            {
            case 1:
                showEmployees();
                break;
            case 2:
                fire();
                break;
            case 3:
                fire();
                break;
            case 4:
                Customer::mainMenu();
                break;
            default:
                cout << "\nInvalid Input!\n";
                cout << "Choose a number between (1-4): ";
                break;
            }
        } while (choice < 1 || choice > 3);

    }

}

void Manager::showEmployees()
{

    cout << "Employees:\n";
    for (int i = 0; i < employeesNum; ++i)
    {
        cout << "Employee #" << i + 1 << ": " << 
    }
}

void Manager::hire()
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

}

void Manager::fire()
{

    showEmployees();
    int choice;
    cout << "Enter the index of the employee you want to fire: ";
    cin >> choice;
    if (choice >= 0 && choice < employeesNum)
    {
        delete employees[choice];
        for (int i = choice; i < employeesNum - 1; ++i)
        {
            employees[i] = employees[i + 1];
        }
        employeesNum--;
        cout << "Employee successfully fired.\n";
    }
    else {
        cout << "Invalid index.\n";
    }
}

