#include "Manager.h"
#include "Customer.h"
#include "Employee.h"
#include <vector>

vector<Employee> Manager::employees;

Manager::Manager() {

  employees.push_back(Employee("Ebrahim", 19, 100));
  employees.push_back(Employee("Khaled", 25, 200));
  managerPage();
}

void Manager::managerPage() {

  if (employees.size() <= 4) {
    cout << "     1.Show Employees                   2.Hire\n";
    cout << "     3.Fire                             4.Back\n";

    int choice;
    do {
      cin >> choice;
      switch (choice) {
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
    } while (choice < 1 || choice > 4);
  } else {
    cout << "     1.Show Employees                   2.Fire\n";
    cout << "     3.Back\n";

    int choice;
    do {
      cin >> choice;
      switch (choice) {
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

void Manager::showEmployees() {

  cout << "Employees:\n";
  for (int i = 0; i < employees.size(); ++i) {
    cout << "Employee #" << i + 1 << ": " << employees.at(i).getName() << endl;
    cout << employees.at(i).getName() << " Age: " << employees.at(i).getAge()
         << endl;
    cout << employees.at(i).getName()
         << " Salary: " << employees.at(i).getSalary() << endl
         << endl;
  }

  cout << "Enter any key to back ";
  string temp;
  cin >> temp;
  managerPage();
}

void Manager::hire() {

    // You need to ensure that you will hire a new Employee

  cout << "======== Hiring a new Employee ========\n\n";

  cout << "Enter the name of the new employee: ";
  string name;
  cin >> name;

  cout << "Enter the age of the new employee: ";
  int age;
  cin >> age;

  cout << "Enter the salary of the new employee: ";
  double salary;
  cin >> salary;

  employees.push_back(Employee(name, age, salary));
  cout << employees.back().getName() << " has become a new employee.\n\n";

  cout << "Enter any key to back ";
  string temp;
  cin >> temp;
  managerPage();

}

void Manager::updateEmployeeData() {


    cout << "Which Employee data do you want to update?\n\n";
    for (int i = 0; i < employees.size(); ++i) {
        cout << i + 1 << ". " << employees.at(i).getName() << endl;
    }
    cout << employees.size() + 1 << ". Back\n";

    int choice;
    do {
        cout << "Your Choice: ";
        cin >> choice;

        if (choice == employees.size() + 1) {
            managerPage();
        }
        else if (choice > 0 || choice < employees.size() + 1) {
            // Updating existing employee logic

        }
        else {
            cout << "\nInvalid Input!\n";
        }
    } while (choice < 0 || choice > employees.size() + 1);


}

void Manager::fire() {
  cout << "Which one do you want to FIRE :-\n\n";
  for (int i = 0; i < employees.size(); i++) {
    cout << i + 1 << ". " << employees.at(i).getName() << endl;
  }
  cout << employees.size() + 1 << ". Back\n\n";

  int choice;
  do {
    cout << "Your Choice: ";
    cin >> choice;

    if (choice == employees.size() + 1) {
      managerPage();
    } else if (choice > 0 || choice < employees.size() + 1) {
        // Make fire logic on the vector
        cout << "Done! " << employees.at(choice - 1).getName() << " has been FIRED\n\n";
        employees.erase(employees.begin() + choice - 1);

        cout << "Enter any key to back ";
        string temp;
        cin >> temp;
        managerPage();
    } else {
      cout << "\nInvalid Input!\n";
    }
  } while (choice < 0 || choice > employees.size() + 1);
}