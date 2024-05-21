
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class book {
public:
    struct B_books {
        string name;
        string author;
        string date;


        B_books();
        B_books(string n, string auth, string dt);
    };
    // Customers data
    std::vector<std::string> name;
    std::vector<long long> id;
    std::vector<long> phoneNumber;
    void takePersonInfo();

    void borrow_section();
    void return_section();

private:
    static const int bookSize = 10; // Made it a constant static member
    static B_books objects[bookSize]; // Declare objects array as static
    static B_books b_objects[bookSize];

    void print_books(B_books* arr);
    void print_book_details(B_books* arr, int bookNum);
    int num_B(B_books* arr);
    void borrow(int bookNum);
    void return_book(int bookNum);
    void print__();
};

// BOOK_H


/*#pragma once
#include "Customer.h"
#include "Manager.h"

//#include <iostream>

//using namespace std;
class book {
    struct B_books {

        string name;
        string author;
        string date;
    public:
        B_books() {
            name = "";
            author = "";
            date = "";
        }
        B_books(string n, string auth, string dt)
            :name(n), author(auth), date(dt)
        {}
    };
    int bookSize = 10;
    //B_books objects[10]={};
    B_books objects[10] = { B_books("Clean Code" ,"Robert C.Martin","2008"),
                           B_books("The Pragmatic Programmer","Andrew Hunt and David Thomas","1999"),
                           B_books("The Mythical Man-month" ,"Frederick Brooks","1975"),
                           B_books("Design Patterns","Erich Gamma","1994"),
                           B_books("Introduction to the Theory of Computation"," Michael Sipser","1997"),
                           B_books("Structure and Interpretation of Computer Programs","Harold Abelson","1996"),
                           B_books("Effective Java","Joshua Bloch"," 2008"),
                           B_books("Code Complete","Steve McConnell","2004"),
                           B_books("Introduction to Algorithms","Thomas H. Cormen"," 2009"),
                           B_books("Head First Design Patterns"," Eric Freeman","2004") };
    B_books b_objects[10] = {};
    void print_books(struct B_books* arr) {
        for (int i = 0; i < bookSize; i++) {
            if (arr[i].name != "")
                cout << i + 1 << ")" << arr[i].name << endl;
        }
    }

    void print_book_details(struct B_books* arr, int bookNum) {
        cout << "==========================\n";
        cout << "=======BOOK DETAILS=======\n";
        cout << "Name : " << arr[bookNum - 1].name;
        cout << "\nAuthor : " << arr[bookNum - 1].author;
        cout << "\nDate of publication : " << arr[bookNum - 1].date << "\n";
    }

    int num_B(struct B_books* arr);

    void borrow(int bookNum) {
        //for (int i =0;i<bookSize;i++)
        //{
            //if (objects[bookNum-1].name == objects[i].name) {
        for (int j = 0; j < bookSize; j++) {
            if (b_objects[j].name == "") {
                b_objects[j] = objects[bookNum - 1];
                cout << "The book \"" << b_objects[j].name << "\" has been borrowed Successfully\n";
                break;
            }
        }
        int x = num_B(objects);
        if (bookNum == x) {
        }
        else {
            for (int z = bookNum - 1; z < bookSize; z++) {
                objects[z] = objects[z + 1];
            }
        }
        objects[9] = {};
        //}//else{cout<<"book is not available\nTry another book";}
    //}
    }

    void return_book(int bookNum) {
        for (int i = 0; i <= bookSize; i++) {
            if (objects[i].name == "") {
                objects[i] = b_objects[bookNum - 1];
                cout << "The book \"" << objects[i].name << "\" has been returned Successfully\n";
                for (int z = bookNum - 1; z < bookSize; z++) {
                    b_objects[z] = b_objects[z + 1];
                }
                b_objects[9] = {};
                break;
            }
        }
    }

    int num_B(struct B_books* arr) {
        for (int i = 0; i < bookSize; i++) {
            if (arr[i].name == "") {
                return (i + 1);
                break;
            }
        }
        return 10;
    }

    //int search(string* arr,string name){
    //    for(int i=0;i<5;i++){
    //        if(name==arr[i])return i+1;
    //
    //    }return false;
    //}

    void print__() {
        cout << "+------------------------------------+\n";
    }

    void borrow_section() {
        int input, in;
        cout << "\n========Borrowing section========\n\n";
        cout << "This is the available books\n";
        cout << "Choose a book\n";
        print_books(objects);
        do {
            cout << "\nEnter the book number : ";
            cin >> input;
            if (input < 1 || input > num_B(objects)) cout << "\nInvalid Input...\nTry again\n";
        } while (input < 1 || input > num_B(objects));

        print_book_details(objects, input);
        do {
            cout << "Do you want to borrow this book?\n";
            cout << "1-Yes            2-No\n";
            cin >> in;
            if (in < 1 || in>2) { cout << "Invalid Input...\nTry again\n"; }
        } while (in < 1 || in>2);
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


        //    if(in==1) {
        //        borrow(input);
        //        cout << "The book has been borrowed Successfully\n";
        //    }
        //    else {
        //        cout<<"The book is not borrowed\n";
        //        cout<<"You will be directed to the MAIN\n";
        //    }
    }
    void return_section() {
        int input, in;
        cout << "\n========Return section========\n\n";
        cout << "This is the borrowed books\n";
        cout << "Choose the book number you want to return\n";
        print_books(b_objects);
        do {
            cout << "\nEnter the book number : ";
            cin >> input;
            if (input < 1 || input > num_B(b_objects)) cout << "\nInvalid Input...\nTry again\n";
        } while (input < 1 || input > num_B(b_objects));

        print_book_details(b_objects, input);
        do {

            cout << "\nAre you sure this is the book you want to return?\n";
            cout << "1-Yes            2-No\n";
            cin >> in;
            if (in < 1 || in>2) { cout << "Invalid Input...\nTry again\n"; }
        } while (in < 1 || in>2);
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
    }
};*/