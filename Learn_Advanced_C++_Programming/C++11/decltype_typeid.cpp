#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
    string str = "Karla";
    decltype(str) name = "Bob";
    bool areSameType = (typeid(str).name() == typeid(name).name());
    cout << typeid(str).name() << " == "<< typeid(name).name() << ": " << areSameType << endl;
    if(areSameType)
    {
        cout << "Type of " << str << " is the same as the type of " << name << endl;
    }
    return 0;
}