#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int age;
    double salary;

public:
    Employee(string name, int age, double salary);

    string getName();

    int getAge();

    double getSalary();
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
}
*/

