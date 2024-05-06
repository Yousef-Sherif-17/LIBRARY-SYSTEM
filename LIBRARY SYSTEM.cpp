#include <iostream>
using namespace std;

class client
{
private:
    string name;
    long number;
    long long id;
public:
    void set_name(string n)
    {
        name = n;
    }
    string get_name()
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


class Librarian
{
private:
    string name;

};



int main()
{
    cout << "Hello World!\n";
}