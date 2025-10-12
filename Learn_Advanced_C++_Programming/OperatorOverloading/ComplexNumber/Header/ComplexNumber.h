#ifndef ComplexNumber_H_
#define ComplexNumber_H_

#include <iostream>
using namespace std;

namespace CmpxNo
{

class im {
private:
    double value;
public:
    im();
    im(double v);
    operator double() const;
};

class ComplexNumber
{
private:
    double real;
    im imag;
public:
    ComplexNumber();
    ComplexNumber(const ComplexNumber& other);
    ComplexNumber(double real, im imag);
    ~ComplexNumber();
    const ComplexNumber& operator=(const ComplexNumber& other);
    double getReal() const;
    im getImag() const;
    const bool operator==(const ComplexNumber& other) const;
    const ComplexNumber operator*() const;
    const ComplexNumber operator*(const ComplexNumber& other) const;
};

ostream& operator<<(ostream& out, const ComplexNumber& obj);

const ComplexNumber operator+(const ComplexNumber& A, const ComplexNumber& B);
const ComplexNumber operator+(const ComplexNumber& A, const double& B);
const ComplexNumber operator+(const double& B, const ComplexNumber& A);
const ComplexNumber operator+(const ComplexNumber& A, const im& B);
const ComplexNumber operator+(const im& B, const ComplexNumber& A);

}

#endif