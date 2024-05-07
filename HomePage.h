#pragma once
#include <iostream>
#include "Librarian.h"

class HomePage
{

public:
	HomePage() {
		std::cout << "1.Client     2.Librarian\n";
		int choice;
		std::cout << "\n Your choice: ";
		std::cin >> choice;
		std::cout << "\n1. borrow a book.		2. return a book. \n 3. search a book.		4. back.\n";
		if (choice == 1)
		{
			Client();
		}
		else Librarian();
	}

};

