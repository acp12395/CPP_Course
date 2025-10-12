#include<iostream>
#include<string>

using namespace std;

void bar(string& A, string& B, string& C)
{
    cout << A << B << C << endl;
}

template<typename A, typename B, typename C>
void foo(A&& a, B&& b, C&& c)
{
    bar(forward<A>(a),forward<B>(b),forward<C>(c));
}

int main()
{
    string A = string{"A"};
    string B = string{"B"};
    string&& C = string{"C"};
    string& refA = A;
    string& refB = B;
    string& refC = C;
    foo(refA,refB,refC);
    return 0;
}