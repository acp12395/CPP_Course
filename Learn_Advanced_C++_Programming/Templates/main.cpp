#include <iostream>
#include "..\OperatorOverloading\ComplexNumber\Header\ComplexNumber.h"
#include ".\Header\Template.h"

using namespace std;
using namespace CmpxNo;

template<typename T>
void print(T obj)
{
    cout << "Print from generic function: ";
    cout << obj << endl;
}

template<class T>
void print(Test<T> obj)
{
    cout << "Print from specific function: ";
    obj.print();
}

int main()
{
    Test<ComplexNumber> complexNumberWrapper(ComplexNumber(1.3,4.1));
    print(complexNumberWrapper);
    cout << "Extra method to print -> class method print:" << endl;
    complexNumberWrapper.print();
    Test<string> stringWrapper("Hello World!");
    print(stringWrapper);
    cout << "Extra method to print -> class method print:" << endl;
    stringWrapper.print();
    Test<int> intWrapper(1);
    print(intWrapper);
    cout << "Extra method to print -> class method print:" << endl;
    intWrapper.print();
    int integer = 3;
    print(integer);

    cout << float() << endl;
    
    return 0;
}