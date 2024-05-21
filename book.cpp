#include "Book.h"
#include "Customer.h"
#include "Manager.h"




void book::takePersonInfo() // These function gonna go to borrow section
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

}
// Constructor Definitions
book::B_books::B_books() : name(""), author(""), date("") {}

book::B_books::B_books(string n, string auth, string dt) : name(n), author(auth), date(dt) {}

// Initialize objects array
book::B_books book::objects[10] = {
    book::B_books("Clean Code", "Robert C.Martin", "2008"),
    book::B_books("The Pragmatic Programmer", "Andrew Hunt and David Thomas", "1999"),
    book::B_books("The Mythical Man-month", "Frederick Brooks", "1975"),
    book::B_books("Design Patterns", "Erich Gamma", "1994"),
    book::B_books("Introduction to the Theory of Computation", "Michael Sipser", "1997"),
    book::B_books("Structure and Interpretation of Computer Programs", "Harold Abelson", "1996"),
    book::B_books("Effective Java", "Joshua Bloch", "2008"),
    book::B_books("Code Complete", "Steve McConnell", "2004"),
    book::B_books("Introduction to Algorithms", "Thomas H. Cormen", "2009"),
    book::B_books("Head First Design Patterns", "Eric Freeman", "2004")
};

book::B_books book::b_objects[10] = {};
// Method Definitions

void book::print_books(B_books* arr) 
{
    for (int i = 0; i < bookSize; i++) 
    {
        if (arr[i].name != "")
        {
            cout << "[" << i + 1 << "] " << arr[i].name << endl;
        }
    }
            std::cout << "------------------------------------------------\n";
}

void book::print_book_details(B_books* arr, int bookNum) {
    cout << "\n\n----------------- BOOK DETAILS -----------------\n";
    cout << "Name : " << arr[bookNum - 1].name;
    cout << "\nAuthor : " << arr[bookNum - 1].author;
    cout << "\nDate of publication : " << arr[bookNum - 1].date << "\n";
    cout << "------------------------------------------------\n\n\n";

}

int book::num_B(B_books* arr) {
    for (int i = 0; i < bookSize; i++) {
        if (arr[i].name == "") {
            return (i + 1);
        }
    }
    return bookSize;
}

void book::borrow(int bookNum) 
{
    for (int j = 0; j < bookSize; j++)
    {
        if (b_objects[j].name == "")
        {
            b_objects[j] = objects[bookNum - 1];
            cout << "------------------------------------------------\n";
            cout << "\"" << b_objects[j].name << "\" has been borrowed \n";
            cout << "------------------------------------------------\n\n\n";
            break;
        }
    }
    int x = num_B(objects);
    if (bookNum != x) {
        for (int z = bookNum - 1; z < bookSize - 1; z++)
        {
            objects[z] = objects[z + 1];
        }
    }
    objects[bookSize - 1] = {};
    //Customer::mainMenu();
    
    std::cout << "------------------------------------------------\n";
    std::cout << "  Do you want to borrow another book?\n";
    std::cout << "   1.Yes                       2.No\n";
    std::cout << "------------------------------------------------\n";
    std::cout << "Your choice: ";
    int borrowAgain;
    std::cin >> borrowAgain;
    std::cout << "------------------------------------------------\n\n\n";

    switch (borrowAgain)
    {
    case 1:
        borrow_section();
        break;
    case 2:
       Customer :: mainMenu();
       break;
    default:
        break;
    }
    
}

void book::borrow_section() 
{
    int input, ifBorrow;
    std::cout << "\n\n------------------------------------------------\n";
    std::cout << "Which book would you want to borrow?\n";
    std::cout << "------------------------------------------------\n";

    print_books(objects);
    do {
        cout << "Your choice: ";
        cin >> input;
        std::cout << "------------------------------------------------\n";

        if (input < 1 || input > num_B(objects))
        {
            cout << "\nInvalid Input...Choose a number between(1 - " << num_B(objects) <<")\n";
        }
    } while (input < 1 || input > num_B(objects));

    print_book_details(objects, input);
        std::cout << "------------------------------------------------\n";
        std::cout << "  Do you want to borrow this book?\n";
        std::cout << "   1.Yes                    2.No\n";
        std::cout << "------------------------------------------------\n";
        do {
        std::cout << "Your choice: ";
        std::cin >> ifBorrow;
        std::cout << "------------------------------------------------\n";

        
            if (ifBorrow < 1 || ifBorrow > 2)
            {
            cout << "\nInvalid Input...Choose a number between(1 - 2)";
            }
      
    } 
    while (ifBorrow < 1 || ifBorrow > 2);
 
    switch (ifBorrow) 
    {
    case 1: 
            std::cout << "\n\n================================================\n";
            std::cout << "      We will collect your personal data     \n";
            std::cout << "================================================\n";
            book::takePersonInfo();
        borrow(input);
        cout << "The book has been borrowed Successfully\n";
        break;
    
    case 2: 
        cout << "You will be directed to the MAIN PAGE\n";
        std::cout << "------------------------------------------------\n\n\n";

        Customer::mainMenu();
        break;
    }
}

void book::return_book(int bookNum) 
{
    for (int i = 0; i <= bookSize; i++) 
    {
        if (objects[i].name == "") 
        {
            objects[i] = b_objects[bookNum - 1];
            cout << "You returned \"" << objects[i].name << "\" \n";
            std::cout << "------------------------------------------------\n\n\n";
            for (int z = bookNum - 1; z < bookSize - 1; z++) 
            {
                b_objects[z] = b_objects[z + 1];
            }
            b_objects[bookSize - 1] = {};
            break;
        }
    }
}

void book::return_section() {
    int input, ifReturn;
    std::cout << "------------------------------------------------\n";
    std::cout << "Which book would you want to return?\n";
    std::cout << "------------------------------------------------\n";

    print_books(b_objects);
    do {
        cout << "Your choice: ";
        cin >> input;
        std::cout << "------------------------------------------------\n";
        
        if (input < 1 || input > num_B(b_objects))
        {
            cout << "\nInvalid Input...\n";
        }
    } while (input < 1 || input > num_B(b_objects));

    print_book_details(b_objects, input);
    do {
        std::cout << "------------------------------------------------\n";
        std::cout << "  Are you sure you want to return this book?\n";
        std::cout << "   1.Yes                              2.No\n";
        std::cout << "------------------------------------------------\n";
        std::cout << "Your choise: ";
        cin >> ifReturn;
        std::cout << "------------------------------------------------\n";

        if (ifReturn < 1 || ifReturn > 2)
        {
            cout << "Invalid Input...\n"; 
        }
    } while (ifReturn < 1 || ifReturn > 2);
    
    switch (ifReturn) {
    case 1: 
        return_book(input);
        break;
    
    case 2: 
        std::cout << "\n\n------------------------------------------------\n";
        std::cout << "This book has not been returned\n";
        std::cout << "You will be directed to the MAIN\n";
        std::cout << "------------------------------------------------\n\n\n";

        Customer::mainMenu();
        break;
    
    }
    Customer::mainMenu();
}
