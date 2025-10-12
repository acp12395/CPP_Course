#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<typename T>
auto testEqualsOperator(T A, T B) -> decltype(A==B)
{
    return A==B;
}

class equalIntVerifier
{
private:
    int val;
public:
    equalIntVerifier(int val):val(val){}
    string operator==(const equalIntVerifier& other) const
    {
        string retStr;
        if(val == other.getVal())
        {
            retStr = "They are equal";
        }
        else
        {
            retStr = "They are different";
        }
        return retStr;
    }
    int getVal() const
    {
        return val;
    }
};

int main()
{
    cout << testEqualsOperator(3,2) << endl;
    cout << testEqualsOperator(equalIntVerifier(3),equalIntVerifier(2)) << endl;
    cout << testEqualsOperator(1,1) << endl;
    cout << testEqualsOperator(equalIntVerifier(1),equalIntVerifier(1)) << endl;
    return 0;
}