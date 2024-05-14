#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int age;
    double salary;

public:
    Employee(string name, int age, double salary) {
        this->name = name;
        this->age = age;
        this->salary = salary;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    double getSalary() {
        return salary;
    }
};



class Company {

private:
    Employee* employees[4];
    int numEmployees;

public:
    Company() {
        numEmployees = 0;
    }

    void hire(string name, int age, double salary) 
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
                HomePage();
            default:
                break;
            }
        }
              
    }

    void fire() {
        showEmployees();
        int choice;
        cout << "Enter the index of the employee you want to fire: ";
        cin >> choice;
        if (choice >= 0 && choice < numEmployees) {
            delete employees[choice];
            for (int i = choice; i < numEmployees - 1; ++i) {
                employees[i] = employees[i + 1];
            }
            numEmployees--;
            cout << "Employee successfully fired.\n";
        }
        else {
            cout << "Invalid index.\n";
        }
    }
    
            void showEmployees()
            {
                cout << "Employees:\n";
                for (int i = 0; i < numEmployees; ++i) 
                {
                    cout << i << ". Name: " << employees[i]->getName() << ", Age: " << employees[i]->getAge() << ", Salary: " << employees[i]->getSalary() << "\n";
                }
            }

    void hireNewEmployee() {
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
};

/*
int main() {
    Company company;
    string choice;

    cout << "Welcome to the company management system!\n";

    while (true) {
        cout << "Would you like to hire, fire, or exit? (hire/fire/exit): ";
        cin >> choice;
        if (choice == "hire") {
            company.hireMenu();
        }
        else if (choice == "fire") {
            company.fire();
        }
        else if (choice == "exit") {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}*/


