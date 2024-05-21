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
      std::cout << "\n------------------- Manager --------------------\n";
           cout << "   1.Show Employees             2.Hire\n";
           cout << "   3.Fire                       4.Update Info\n";
           cout << "   5.Back\n";
      std::cout << "------------------------------------------------\n";

    int choice;
    do {
        std::cout << "Your choice: ";
        cin >> choice;
        std::cout << "------------------------------------------------\n\n";
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
          updateEmployeeData();
          break;
      case 5:
        Customer::mainMenu();
        break;
      default:
        cout << "\nInvalid Input!\n";
        cout << "Choose a number between (1-4): ";
        break;
      }
    } while (choice < 1 || choice > 4);
  } else {
     std::cout << "------------------- Manager --------------------\n";
           cout << "     1.Show Employees              2.Fire \n";
           cout << "     3.Update Info                 4.Back\n";
      std::cout << "------------------------------------------------\n";

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
        updateEmployeeData();
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
  std::cout << "\n------------------------------------------------\n";
       cout << "                   Employees:\n";
  std::cout << "------------------------------------------------\n";

  for (int i = 0; i < employees.size(); ++i) {
    cout << "Employee #" << i + 1 << ": " << employees.at(i).getName() << endl;
    cout << employees.at(i).getName() << " Age: " << employees.at(i).getAge() << endl;
    cout << employees.at(i).getName() << " Salary: " << employees.at(i).getSalary() << endl; 
    if(i<employees.size()-1) cout << "-------------------------\n";
  }
    std::cout << "------------------------------------------------\n";

  cout << "Enter any key to back ";
  string temp;
  cin >> temp;
  std::cout << "------------------------------------------------\n\n\n";

  managerPage();
}

void Manager::hire() {

    // You need to ensure that you will hire a new Employee

  cout << "\n============= Hiring a new Employee ============\n";

  cout << "Enter the name of the new employee: ";
  string name;
  cin >> name;

  cout << "Enter the age of the new employee: ";
  int age;
  cin >> age;

  cout << "Enter the salary of the new employee: ";
  double salary;
  cin >> salary;
  cout << "================================================\n";

  employees.push_back(Employee(name, age, salary));
  cout << employees.back().getName() << " has become a new employee.\n";
  cout << "================================================\n";
  cout << "Enter any key to back ";
  string temp;
  cin >> temp;
  cout << "================================================\n\n";
  managerPage();

}

void Manager::updateEmployeeData()
{

    std::cout << "------------------------------------------------\n";
         cout << "Which Employee data do you want to update?\n";
    std::cout << "------------------------------------------------\n";

    for (int i = 0; i < employees.size(); ++i) {
        cout << i + 1 << ". " << employees.at(i).getName() << endl;
    }
    cout << employees.size() + 1 << ". Back\n";
    std::cout << "------------------------------------------------\n";

    int choice;
    do {
        cout << "Your Choice: ";
        cin >> choice;
        std::cout << "------------------------------------------------\n";

        if (choice == employees.size() + 1) {
            managerPage();
        }
        else if (choice > 0 || choice < employees.size() + 1) {
            // Updating existing employee logic
            std::cout << "------------------------------------------------\n";
                 cout << "Which info do you want to change\n";
            std::cout << "------------------------------------------------\n";
            cout << "1." << employees.at(choice - 1).getName() << endl;
            cout << "2." << employees.at(choice - 1).getAge() << endl;
            cout << "3." << employees.at(choice - 1).getSalary() << endl;
            cout << "4." << "Back\n";
            std::cout << "------------------------------------------------\n";
            int updateChoice;
            cout << "Your Choice: ";
            cin >> updateChoice;
            std::cout << "------------------------------------------------\n";

                string newName;
                int newAge;
                double newSalary;
            switch (updateChoice)
            {
            case 1: 
                cout << "Enter the new name: ";
                cin >> newName;
                employees.at(choice - 1).setName(newName);
                std::cout << "------------------------------------------------\n";
                cout << employees.at(choice - 1).getName() << " had been updated!" << endl;
                std::cout << "------------------------------------------------\n";
                managerPage();
                break;
            case 2:
                cout << "Enter the new Age: ";
                cin >> newAge;
                employees.at(choice - 1).setAge(newAge);
                std::cout << "------------------------------------------------\n";
                cout << employees.at(choice - 1).getAge() << " had been updated!" << endl;
                std::cout << "------------------------------------------------\n";
                managerPage();
                break;
            case 3:
                cout << "Enter the new Salary: ";
                cin >> newSalary;
                employees.at(choice - 1).setSalary(newSalary);
                std::cout << "------------------------------------------------\n";
                cout << employees.at(choice - 1).getSalary() << " had been updated!" << endl;
                std::cout << "------------------------------------------------\n";
                managerPage();
                break;
            default:
                break;
            }
        }
        else {
            cout << "\nInvalid Input!\n";
        }
    } while (choice < 0 || choice > employees.size() + 1);


}

void Manager::fire() {
  std::cout << "------------------------------------------------\n";
       cout << "Which one do you want to FIRE :-\n";
  std::cout << "------------------------------------------------\n";
  for (int i = 0; i < employees.size(); i++) 
  {
    cout << i + 1 << "." << employees.at(i).getName() << endl;
  }
  cout << employees.size() + 1 << ".Back\n";
  std::cout << "------------------------------------------------\n";

  int choice;
  do {
    cout << "Your Choice: ";
    cin >> choice;
    std::cout << "------------------------------------------------\n";
    if (choice == employees.size() + 1) {
      managerPage();
    } else if (choice > 0 || choice < employees.size() + 1) {
        // Make fire logic on the vector
        cout << "Done! " << employees.at(choice - 1).getName() << " has been FIRED\n";
        std::cout << "------------------------------------------------\n";

        employees.erase(employees.begin() + choice - 1);

        cout << "Enter any key to back ";
        string temp;
        cin >> temp;
        std::cout << "------------------------------------------------\n\n";

        managerPage();
    } else {
      cout << "\nInvalid Input!\n";
    }
  } while (choice < 0 || choice > employees.size() + 1);
}