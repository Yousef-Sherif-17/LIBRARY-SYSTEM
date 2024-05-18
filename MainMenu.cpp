/*
#include "MainMenu.h"
Customer::MainMenu() {
    std::cout << "------------------- Library --------------------\n";
    std::cout << "     1.Client                   2.Librarian     \n";
    std::cout << "------------------------------------------------\n";
    std::cout << "Your choice: ";
    int choice;
    do
    {
        std::cin >> choice;
        std::cout << "------------------------------------------------\n\n\n";

        switch (choice) {

        case 1:
            std::cout << '\n';
            new Customer();
            break;
        case 2:
            std::cout << '\n';
            // Company::hire();
            break;
        default:
            std::cout << "Choose a number between (1,2): ";
            break;
        }

    } while (choice < 1 || choice > 2);


}

*/