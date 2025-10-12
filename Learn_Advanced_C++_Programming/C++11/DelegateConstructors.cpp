#include<iostream>

using namespace std;

class Parent
{
public:
    Parent()
    {
        cout << "Parent constructor" << endl;
    }
    Parent(const string& str) : Parent()
    {
        cout << "Parent constructor: " << str << endl;
    }
};

class Child : public Parent
{
public:
    Child() : Parent("Hello World!")
    {
        cout << "Child constructor" << endl;
    }
};

int main()
{
    Child child;
    return 0;
}