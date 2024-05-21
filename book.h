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
    static  B_books objects[bookSize]; // Declare objects array as static
    static B_books b_objects[bookSize];

    void print_books(B_books* arr);
    void print_book_details(B_books* arr, int bookNum);
    int num_B(B_books* arr);
    void borrow(int bookNum);
    void return_book(int bookNum);
    void print__();
};

