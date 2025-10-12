#include<iostream>
#include<memory>

using namespace std;

class Test
{
public:
    Test(){cout << "Constructor" << endl;}
    void greet(){cout << "Hello World!" << endl;}
    ~Test(){cout << "Destructor" << endl;}
};

int main()
{
    {
        unique_ptr<Test[]> pTest(new Test[2]);
        pTest[1].greet();
    }
    cout << "Finish";
    return 0;
}