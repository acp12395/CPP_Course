#include <iostream>
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

class noExceptMethodContainer
{
public:
    void method() noexcept
    {
        try{
            throw myException();
        }
        catch(myException& e)
        {
            cout<<"Handled exception: "<<e.what()<<endl;
        }
    }
};

int main()
{
    noExceptMethodContainer obj;
    obj.method();
    cout << "Program finished";
    return 0;
}