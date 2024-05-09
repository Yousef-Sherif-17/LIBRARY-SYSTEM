#pragma once
#include <iostream>
#include "Librarian.h"

class HomePage
{

private:


public:

    HomePage() {

        std::cout << "------------------- Library --------------------\n";
        std::cout << "     1.Client                   2.Librarian\n";
        std::cout << "------------------------------------------------\n";

        std::cout << "Your choice: ";

        int choice;

        do
        {
            std::cin >> choice;
            std::cout << "------------------------------------------------\n\n\n";

            switch (choice)
            {
            case 1:
                std::cout << '\n';
                new Client();
                break;
            case 2:
                std::cout << '\n';
                new Employee();
                break;
            default:
                std::cout << "Choose a number between (1,2): ";
                break;
            }

        } while (choice < 1 || choice > 2);


    }
                                
};

