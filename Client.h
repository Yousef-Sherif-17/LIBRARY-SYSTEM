#pragma once
#include <iostream>
#include <vector>

class Client 
{
private:

    // Book Data
    std::string categories[3] = { "Literary","Political","Scientific" };
    static struct Book {
        std::string name;
        std::string auther;
        int releaseYear;
        double price;
        bool isAvailable = true;
    };
    Book literaryBooks[5] = {
        {"Pride and Prejudice", "Jane Austen", 1990 ,5},
        {"1984", "George Orwell", 2001 ,10},
        {"The Great Gatsby", "F. Scott Fitzgerald", 2005, 15},
        {"Jane Eyre", "Brontë", 2022, 20},
        {"Crime and Punishment", "Fyodor Dostoevsky", 1850, 25}
    };
    Book politicalBooks[5] = {
        {"The Republic","Plato",1980 , 9.5},
        {"The Prince","Niccolo Machiavelli", 1832, 11.30},
        {"Leviathan","Thomas Hobbes", 1651, 4.6},
        {"On Liberty","John Stuart Mill", 1859,15.23},
        {"Democracy in America","Alexis de Tocqueville",1853,19.30}
    };
    Book scientificBooks[5] = {
        {"The Selfish Gene","Richard Dawkins", 1976, 14.20},
        {"The Grand Design","Stephen Hawking", 1811, 8.99},
        {"The Elegant Universe"," Brian Greene", 1965, 12},
        {"The Blind Watchmaker","Richard Dawkins", 1974 , 5.12},
        {"On the Origin of Species","by Charles Darwin", 1988,16}
    };
    

    // Client data
    std::vector<std::string> name;
    std::vector<long long> id;
    std::vector<long> phoneNumber;

public:

    Client() {

        std::cout << "1. borrow a book.		2. return a book.\n";
        std::cout << "3. search a book.		4. back.\n\n";
        std::cout << "Your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            showCategories();
        default:
            break;
        }

    }


    // Private functions
private:

    void showCategories() {

        std::cout << "\nCategories:- \n";
        for (int i = 0; i < 3; i++)
        {
            // "Literary","Political","Scientific"
            std::cout << i + 1 << ". " << categories[i] << "      ";
        }

        std::cout << "\n\nWhich category will you choose: ";

        int categoryChoice;
        std::cin >> categoryChoice;
        std::cout << '\n';

        switch (categoryChoice)
        {
        case 1:
            showBooks(literaryBooks);
            break;
        case 2:
            showBooks(politicalBooks);
            break;
        case 3:
            showBooks(scientificBooks);
            break;
        default:
            break;
        }


    }

    void showBooks(Book bookType[]) {

        /*
        1. ---
        2. ---

        3. ---
        4. ---
        */

        int numOfBorrowedBooks = 0;
        for (int i = 0; i < 5; i++)
        {
            if (bookType[i].isAvailable) {
                std::cout << i + 1 - numOfBorrowedBooks << ". " << bookType[i].name << '\n';
            }
            else {
                numOfBorrowedBooks++;
            }
        }
        std::cout << "\nWhich book will you borrow: ";
        int bookNum;

        do
        {
            std::cin >> bookNum;
            if (bookNum < 1  || bookNum > 5)
            {
                std::cout << "Choose a book between (1,5): ";
            }
        } while (bookNum < 1  || bookNum > 5);
       
        std::cout << '\n';
        showBookDetails(bookType, bookNum - 1);

    }

    void showBookDetails(Book booktype[], int bookNum) {

        /*
        Book name: ---
        Book auther: ---
        Book year of release: ---
        Book price: ---
        */

        std::cout << "Book name: " << booktype[bookNum].name << '\n';
        std::cout << "Book auther: " << booktype[bookNum].auther << '\n';
        std::cout << "Book year of release: " << booktype[bookNum].releaseYear << '\n';
        std::cout << "Book price: " << booktype[bookNum].price << '\n';

        std::cout << "\nDo you want to borrow this book?\n";
        std::cout << "   1.Yes               2.No\n\n";

        std::cout << "Your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            // Taking user info
            std::cout << "You Borrowed " << booktype[bookNum].name << ".\n\n";
            std::cout << "We will collect your personal data\n";
            takePersonInfo();
            // Make the borrowed book unavailable in the libraray
            booktype[bookNum].isAvailable = false;
            std::cout << '\n';
            new Client();

            //new HomePage();
            break;
        case 2:
            std::cout << '\n';
            //new HomePage();
            break;
        default:
            break;
        }


    }

    void takePersonInfo() {

        std::cout << "Enter your name: ";
        std::string personName;
        std::cin >> personName;
        name.push_back(personName);

        std::cout << "Enter your ID: ";
        long long personID;
        std::cin >> personID;
        id.push_back(personID);

        std::cout << "Enter your phone number: ";
        long personPhoneNumber;
        std::cin >> personPhoneNumber;
        phoneNumber.push_back(personPhoneNumber);

    }


    // Public functions


};

