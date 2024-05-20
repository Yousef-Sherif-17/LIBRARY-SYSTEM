#include "Book.h"
#include "Customer.h"
#include "Manager.h"

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
void book::print_books(B_books* arr) {
    for (int i = 0; i < bookSize; i++) {
        if (arr[i].name != "")
            cout << i + 1 << ")" << arr[i].name << endl;
    }
}

void book::print_book_details(B_books* arr, int bookNum) {
    cout << "==========================\n";
    cout << "=======BOOK DETAILS=======\n";
    cout << "Name : " << arr[bookNum - 1].name;
    cout << "\nAuthor : " << arr[bookNum - 1].author;
    cout << "\nDate of publication : " << arr[bookNum - 1].date << "\n";
}

int book::num_B(B_books* arr) {
    for (int i = 0; i < bookSize; i++) {
        if (arr[i].name == "") {
            return (i + 1);
        }
    }
    return bookSize;
}

void book::borrow(int bookNum) {
    for (int j = 0; j < bookSize; j++) {
        if (b_objects[j].name == "") {
            b_objects[j] = objects[bookNum - 1];
            cout << "The book \"" << b_objects[j].name << "\" has been borrowed Successfully\n";
            break;
        }
    }
    int x = num_B(objects);
    if (bookNum != x) {
        for (int z = bookNum - 1; z < bookSize - 1; z++) {
            objects[z] = objects[z + 1];
        }
    }
    objects[bookSize - 1] = {};
}

void book::return_book(int bookNum) {
    for (int i = 0; i <= bookSize; i++) {
        if (objects[i].name == "") {
            objects[i] = b_objects[bookNum - 1];
            cout << "The book \"" << objects[i].name << "\" has been returned Successfully\n";
            for (int z = bookNum - 1; z < bookSize - 1; z++) {
                b_objects[z] = b_objects[z + 1];
            }
            b_objects[bookSize - 1] = {};
            break;
        }
    }
}

void book::borrow_section() {
    int input, in;
    cout << "\n========Borrowing section========\n\n";
    cout << "These are the available books\n";
    cout << "Choose a book\n";
    print_books(objects);
    do {
        cout << "\nEnter the book number: ";
        cin >> input;
        if (input < 1 || input > num_B(objects)) cout << "\nInvalid Input...\nTry again\n";
    } while (input < 1 || input > num_B(objects));

    print_book_details(objects, input);
    do {
        cout << "Do you want to borrow this book?\n";
        cout << "1-Yes            2-No\n";
        cin >> in;
        if (in < 1 || in > 2) { cout << "Invalid Input...\nTry again\n"; }
    } while (in < 1 || in > 2);
    switch (in) {
    case 1: {
        borrow(input);
        cout << "The book has been borrowed Successfully\n";
        break;
    }
    case 2: {
        cout << "The book is not borrowed\n";
        cout << "You will be directed to the MAIN\n";

    }
    }
    Customer::mainMenu();
}

void book::return_section() {
    int input, in;
    cout << "\n========Return section========\n\n";
    cout << "These are the borrowed books\n";
    cout << "Choose the book number you want to return\n";
    print_books(b_objects);
    do {
        cout << "\nEnter the book number: ";
        cin >> input;
        if (input < 1 || input > num_B(b_objects)) cout << "\nInvalid Input...\nTry again\n";
    } while (input < 1 || input > num_B(b_objects));

    print_book_details(b_objects, input);
    do {
        cout << "\nAre you sure this is the book you want to return?\n";
        cout << "1-Yes            2-No\n";
        cin >> in;
        if (in < 1 || in > 2) { cout << "Invalid Input...\nTry again\n"; }
    } while (in < 1 || in > 2);
    switch (in) {
    case 1: {
        return_book(input);
        break;
    }
    case 2: {
        cout << "The book is not returned\n";
        cout << "You will be directed to the MAIN\n";
        Customer::mainMenu();
        break;
    }
    }
    Customer::mainMenu();
}
