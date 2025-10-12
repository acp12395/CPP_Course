#include<iostream>

using namespace std;

void function(const int& ref)
{
    cout << "lvalue function: " << ref << endl;
}

void function(int&& ref)
{
    cout << "rvalue function: " << ref << endl;
}

int main()
{
    int a = 1;
    function(a++);
    function(++a);
    return 0;
}