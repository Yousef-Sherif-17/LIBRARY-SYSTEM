#pragma once
#include <iostream>


class Client 
{
private:

    struct Book {
        std::string name;
        std::string auther;
        int releaseYear;
        double price;
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
        {" The Prince","Niccolo Machiavelli", 1832, 11.30},
        {" Leviathan","Thomas Hobbes", 1651, 4.6},
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

    std::string categories[3] = {"Literary","Political","Scientific"};
    std::string name;
    long number;
    long long id;





public:

    Client() {
        std::cout << "Categories:- \n\n";
        
        for (int i = 0; i < 3; i++)
        {
            std::cout << i + 1 << ". " << categories[i] << "      ";
        }

    }

};



