#include <iostream>

using namespace std;

class Test
{
public:
    Test(){}
    Test(int val){}
    Test(const Test& other)
    {
        cout << "Entered copy constructor" << endl;
    }
};

int main()
{
    Test A(Test(2));
    const Test& ref = Test();
    return 0;
}