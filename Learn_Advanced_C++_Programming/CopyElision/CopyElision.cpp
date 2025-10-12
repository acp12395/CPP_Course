#include<iostream>
#include<vector>

using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Constructor" << endl;
    }
    Test(const Test& other)
    {
        cout << "Copy constructor" << endl;
    }
    Test& operator=(const Test& other)
    {
        cout << "Assignment operator" << endl;
        return *this;
    }
    ~Test()
    {
        cout << "Destructor" << endl;
    }
};

Test builder()
{
    cout << "1.1" << endl;
    return Test();
}

int main()
{
    cout << "1" << endl;
    Test A = builder();
    cout << "2" << endl;
    cout << "vector<Test>:" << endl;
    vector<Test> vec;
    vec.push_back(Test());
    return 0;
}