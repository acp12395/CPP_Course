#include<iostream>

using namespace std;

class Test
{
private:
    int val;
public:
    Test(){}
    Test(int val) : val(val){};
    Test(const Test& other)
    {
        val = other.val;
    }
    Test& operator=(const Test& other)
    {
        val = other.val;
        return *this;
    }
    Test& operator++()
    {
        val++;
        return *this;
    }
    Test operator++(int)
    {
        Test retVal = *this; 
        val++;
        return retVal;
    }
    friend ostream& operator<<(ostream& os,const Test& obj);
};

ostream& operator<<(ostream& os,const Test& obj)
{
    os << obj.val;
    return os;
}

int main()
{
    Test A;
    Test* B = &++A;
    //Test* C = &A++;  A++ is an RValue
    const Test& D = Test();
    return 0;
}