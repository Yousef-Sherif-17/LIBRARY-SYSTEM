#pragma once
#include <iostream>
#include "Librarian.h"

class HomePage
{

private:


public:
	
	HomePage() {

		std::cout << "=================== Library ===================\n\n";
		std::cout << "1.Client     2.Librarian\n\n";
		std::cout << "Your choice: ";
		
		int choice;

		do
		{
			std::cin >> choice;
			switch (choice)
			{
			case 1:
				std::cout << '\n';
				new Client();
				break;
			case 2:
				std::cout << '\n';
				new Librarian();
				break;
			default:
				std::cout << "Choose a number between (1,2): ";
				break;
			}

		} while (choice < 1 || choice > 2);


	}

};

