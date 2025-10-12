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

    friend ostream& operator<<(ostream& out, const Test& A)
    {
        out << "String: " << A.str << endl << "Number: " << A.num;
        return out;
    }
};

int main()
{
    Test A("A",1);
    cout << A << endl;
    return 0;
}