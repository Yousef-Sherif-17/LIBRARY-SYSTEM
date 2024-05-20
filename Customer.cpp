#include "Customer.h"
#include "Manager.h"

// Constructors
Customer::Customer() {

    std::cout << "------------------------------------------------\n";
    std::cout << "      1.Buy a book.             2.Search a book.\n";
    std::cout << "      3.Return a book.          4.Back.\n";
    std::cout << "------------------------------------------------\n";
    std::cout << "Your choice: ";
    int choice;
    do {
        std::cin >> choice;
        switch (choice) {
        case 1:
            showCategories();
        case 2:
            break;
        case 3:
            break;
        case 4:
            mainMenu();
            break;
        default:
            cout << "\nInvalid Input!\n";
            cout << "Choose a number between (1-3): ";
            break;
        }
    } while (choice < 1 || choice > 3);
}

// Functions
void Customer::showCategories()
{
    std::cout << "\n================================================\n";
    std::cout << "                   Categories: \n";
    std::cout << "================================================\n";
    for (int i = 0; i < 3; i++) {

        // "Literary","Political","Scientific"
        std::cout << i + 1 << ". " << categories[i] << "      ";
    }
    std::cout << "\n================================================\n";


    std::cout << "Which category will you choose: ";

    int categoryChoice;
    std::cin >> categoryChoice;
    std::cout << "\n================================================\n";
    std::cout << "\n\n\n";

    do {
        switch (categoryChoice) {

        case 1:
            std::cout << "\n================================================\n";
            std::cout << "                  Literary Books                 \n";
            std::cout << "================================================\n";
            showBooks(literaryBooks);
            break;
        case 2:
            std::cout << "\n================================================\n";
            std::cout << "                  Political Books                 \n";
            std::cout << "================================================\n";
            showBooks(politicalBooks);
            break;
        case 3:
            std::cout << "\n================================================\n";
            std::cout << "                  Scientific Books                \n";
            std::cout << "================================================\n";
            showBooks(scientificBooks);
            break;
        default:
            std::cout << "Choose a number between (1-3): ";
            break;
        }
    } while (categoryChoice < 1 || categoryChoice > 3);

}

void Customer::showBooks(Book bookType[]) {

    for (int i = 0; i < 5; i++) {
        std::cout << i + 1 << ". " << bookType[i].name << '\n';
    }
    std::cout << "================================================\n";
    std::cout << "Which book will you buy: ";
    int bookNum;

    std::cin >> bookNum;
    std::cout << "================================================\n\n\n";
    if (bookNum < 1 || bookNum > 5) {
        std::cout << "Choose a book between (1,5): ";
    }

    std::cout << '\n';
    showBookDetails(bookType, bookNum - 1);

}

void Customer::showBookDetails(Book booktype[], int bookNum) {

    /*
    Book name: ---
    Book auther: ---
    Book year of release: ---
    Book price: ---
    */
    std::cout << "================================================\n";
    std::cout << "Book name: " << booktype[bookNum].name << '\n';
    std::cout << "Book auther: " << booktype[bookNum].auther << '\n';
    std::cout << "Book year of release: " << booktype[bookNum].releaseYear << '\n';
    std::cout << "Book price: " << booktype[bookNum].price << " $" << '\n';
    std::cout << "================================================\n";

    std::cout << "\n------------------------------------------------\n";
    std::cout << "  Do you want to buy this book?\n";
    std::cout << "   1.Yes               2.No\n";
    std::cout << "------------------------------------------------\n";
    std::cout << "Your choice: ";
    int choice;
    std::cin >> choice;
    std::cout << "------------------------------------------------\n\n\n";

    switch (choice)
    {
    case 1:
        // Taking user info
        //std::cout << "You bought " << booktype[bookNum].name << ".\n\n";
        std::cout << "================================================\n";
        std::cout << "      We will collect your personal data     \n";
        std::cout << "================================================\n";
        takePersonInfo();
        // std::cout << "================================================\n\n\n";//نهاية thank u
        std::cout << '\n';
        break;
    case 2:
        Customer::mainMenu();
        /*
        std::cout << "================================================\n";
        std::cout << "=                  GO TO HELL!                 =\n";
        std::cout << "================================================\n";
        */
        break;
    default:
        std::cout << "Choose a number between (1-2): ";
        break;
    }
}

void Customer::buyAgain()
{
    std::cout << "------------------------------------------------\n";
    std::cout << "  Do you want to buy another book?\n";
    std::cout << "     1.Yes               2.No\n";
    std::cout << "------------------------------------------------\n";
    std::cout << "Your choice: ";
    int again;
    std::cin >> again;
    std::cout << "------------------------------------------------\n\n\n";

    switch (again)
    {
    case 1:
        showCategories();
        break;
    case 2:
        Customer::mainMenu();
    
        /*
        std::cout << "================================================\n";
        std::cout << "=           Thank You For Visiting Us          =\n";
        std::cout << "================================================\n";
        */
        break;
    default:
        std::cout << "Choose a number between (1-2): ";
        break;
    }

}

void Customer::takePersonInfo() // These function gonna go to borrow section
{
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
    std::cout << "================================================\n\n\n";

    buyAgain();
}

// General fucntions
void Customer::mainMenu() {
    std::cout << "------------------- Library --------------------\n";
    std::cout << "      1.Customer                  2.Librarian   \n";
    std::cout << "      3.Exit                                    \n";
    std::cout << "------------------------------------------------\n";
    std::cout << "Your choice: ";
    int choice;
    do
    {
        std::cin >> choice;
        std::cout << "------------------------------------------------\n\n\n";
        int password = 1234;
        int pass;
        switch (choice)
        {
        case 1:
            std::cout << '\n';
            new Customer();
            break;
        case 2:
            std::cout << "------------------------------------------------\n";
            std::cout << "Enter the password: ";
            std::cin >> pass;
            std::cout << "------------------------------------------------\n\n";
            if (pass==password) {
            std::cout << '\n';
            new Manager();
            }
            else Customer::mainMenu();
            break;
        case 3:
            Customer::exit();
            break;
        default:
            std::cout << "Choose a number between (1-3): ";
            break;
        }
    } while (choice < 1 || choice > 3);


}

void Customer::exit()
{
    std::cout << "\n==========================\n";
    std::cout << "    Visit Us Again <3\n";
    std::cout << "==========================\n";
}
