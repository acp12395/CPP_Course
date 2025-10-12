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
    shared_ptr<Test> ptr1(nullptr);
    {
        shared_ptr<Test> ptr2 = make_shared<Test>();
        ptr2->greet();
        ptr1 = ptr2;
    }
    cout << "Finish" << endl;
    return 0;
}