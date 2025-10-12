#include <iostream>
#include <string>
using namespace std;

void goesWrong()
{
    bool error1 = false;
    bool error2 = false;
    bool error3 = true;

    if(error1)
    {
        throw 1;
    }
    if(error2)
    {
        throw "Raw string exception";
    }
    if(error3)
    {
        throw string("String Exception");
    }
}

void useGoesWrong()
{
    goesWrong();
    cout << "Not logged";
}

int main()
{
    try
    {
        useGoesWrong();
    }
    catch(int e)
    {
        cout << "Exception handling: code " << e << endl;
    }
    catch(char const* e)
    {
        cout << "Exception handling: " << e << endl;
    }
    catch(string& e)
    {
        cout << "Exception handling: " << e << endl;
    }
    return 0;
}