#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Test
{
private:
    string str;
    int num;
public:
    Test()
    {

    }
    Test(string passingStr, int passingNum)
    {
        str = passingStr;
        num = passingNum;
    }
    Test(const Test& other)
    {
        cout << "Called copy constructor" << endl;
        str = other.str;
        num = other.num;
    }
    ~Test()
    {
        str = "";
        num = 0;
    }
    void print()
    {
        cout << "String: " << str << endl << "Number: " << num;
    }

    Test& operator=(const Test& other)
    {
        cout << "Called operator=" << endl;
        str = other.str;
        num = other.num;
        return *this;
    }
};

int main()
{
    Test A("A",1);
    A.print();
    cout << endl;
    Test B = A;
    B.print();
    cout << endl;
    Test C;
    C = A;
    C.print();
    cout << endl;
    Test D("D",4);
    A = B = C = D;
    A.print();
    return 0;
}