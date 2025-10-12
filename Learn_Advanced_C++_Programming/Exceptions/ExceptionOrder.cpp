#include <iostream>
#include <string>
#include <exception>
using namespace std;

class myException : public exception
{
public:
    virtual const char* what()
    {
        return "My exception";
    }
};

class exceptionThrowMethodContainer
{
public:
    void method()
    {
        throw myException();
    }
};

int main()
{
    exceptionThrowMethodContainer obj;
    try
    {
        obj.method();
    }
    catch(myException& e)
    {
        cout << "Subclass exception should be handled first" << endl;
        cout << "Exception: " << e.what();
    }
    catch(exception& e)
    {
        cout << "Base class exception should be handled after" << endl;
        cout << "Exception: " << e.what() << endl;
    }
    cout << "Program finished";
    return 0;
}