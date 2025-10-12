#include<iostream>
#include<functional>

using namespace std;
using namespace placeholders;

class Test
{
public:
    int sum(int A, int B, int C)
    {
        cout << A << " + " << B << " + " << C << endl;
        return A+B+C;
    }
};

int main()
{
    Test obj;
    function<int(int,int)> func = bind(Test::sum, obj, _2, 100, _1);
    cout << func(1,2) << endl;
    return 0;
}