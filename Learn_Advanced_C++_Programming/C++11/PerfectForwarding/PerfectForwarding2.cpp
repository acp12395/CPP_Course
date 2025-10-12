#include<iostream>
#include<string>

using namespace std;

void check(string& A)
{
    cout << "lvalue ref" << endl;
}

void check(string&& A)
{
    cout << "rvalue ref" << endl;
}

template<typename T>
void call(T&& a)
{
    check(forward<T>(a));
}

int main()
{
    call(string{"a"});
    string&& rvalueRef = string{"A"};
    string obj;
    string& lvalueRef = obj;
    check(obj);
    check(rvalueRef);
    check(lvalueRef);
    return 0;
}