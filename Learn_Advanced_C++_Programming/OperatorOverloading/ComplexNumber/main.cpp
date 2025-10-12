#include <iostream>
#include "Header\ComplexNumber.h"

using namespace std;
using namespace CmpxNo;

int main()
{
    ComplexNumber A(3.1, 5.05);
    ComplexNumber B = A;
    ComplexNumber C = A + B;
    ComplexNumber D = A + 2.1;
    ComplexNumber E = 2.1 + A;
    ComplexNumber F = A + im(4.1);
    ComplexNumber G = im(4.1) + A;


    cout << "B = " << B << endl;
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "E = " << E << endl;
    cout << "F = " << F << endl;
    cout << "G = " << G << endl;
    cout << (A == B) << endl;
    cout << *A << endl;
    cout << B*C << endl;
    cout << ComplexNumber(6,4)*ComplexNumber(6, -4) << endl;
    return 0;
}