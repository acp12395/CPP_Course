#include<iostream>

using namespace std;

class Parent
{
public:
    virtual void method(){}
};

class Brother : public Parent
{
public:
    Brother(){}
};

class Sister : public Parent
{
public:
    Sister(){}
};

int main()
{
    Parent parent;
    Brother brother;
    Sister sister;

    Parent* ptrP;
    Brother* ptrB;

    ptrP = &sister;
    ptrB = static_cast<Brother*>(ptrP);
    if(ptrB == nullptr)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        cout << "Valid" << endl;
    }

    ptrP = &parent;
    ptrB = static_cast<Brother*>(ptrP);
    if(ptrB == nullptr)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        cout << "Valid" << endl;
    }

    ptrP = &brother;
    ptrB = static_cast<Brother*>(ptrP);
    if(ptrB == nullptr)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        cout << "Valid" << endl;
    }
    return 0;
}