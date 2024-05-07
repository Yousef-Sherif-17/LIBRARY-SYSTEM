#pragma once
#include <iostream>


class Client
{
private:

    struct Book {
        std::string name;
        std::string auther;
        // int releaseYear;
        double price;
    };
    Book literaryBooks[5] = {
        {"Pride and Prejudice", "Jane Austen", 5}
        ,{"1984", "George Orwell", 10}
        ,{"The Great Gatsby", "F. Scott Fitzgerald", 15}
        ,{"Jane Eyre", "Brontë", 20}
        ,{"Crime and Punishment", "Fyodor Dostoevsky", 25}
    };

    
    std::string name;
    long number;
    long long id;




public:

    Client() {


    }

};



