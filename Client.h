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

    std::string name;
    long number;
    long long id;
public:
    void set_name(std::string n)
    {
        name = n;
    }
    std::string get_name()
    {
        return name;
    }
    void set_number(long num)
    {
        number = num;
    }
    long get_number()
    {
        return number;
    }
    void set_id(long long Id)
    {
        id = Id;
    }
    long long get_id()
    {
        return id;
    }
};



