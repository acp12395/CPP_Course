#include "..\Header\ComplexNumber.h"

namespace CmpxNo
{

ComplexNumber::ComplexNumber() : real(0), imag(0) {}

ComplexNumber::ComplexNumber(const ComplexNumber& other)
{
    real = other.real;
    imag = other.imag;
}

ComplexNumber::ComplexNumber(double real, im imag) : real(real), imag(imag) {}

ComplexNumber::~ComplexNumber()
{

}

const ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other)
{
    real = other.real;
    imag = other.imag;
    return *this;
}

double ComplexNumber::getReal() const
{
    return real;
}

im ComplexNumber::getImag() const
{
    return imag;
}

ostream& operator<<(ostream& out, const ComplexNumber& obj)
{
    out << obj.getReal() << ", " << obj.getImag();
    return out;
}

const ComplexNumber operator+(const ComplexNumber& A, const ComplexNumber& B)
{
    return ComplexNumber(A.getReal() + B.getReal(), A.getImag() + B.getImag());
}

const ComplexNumber operator+(const ComplexNumber& A, const double& B)
{
    return ComplexNumber(A.getReal() + B, A.getImag());
}

const ComplexNumber operator+(const double& B, const ComplexNumber& A)
{
    return ComplexNumber(A.getReal() + B, A.getImag());
}

const ComplexNumber operator+(const ComplexNumber& A, const im& B)
{
    return ComplexNumber(A.getReal(), A.getImag() + B);
}

const ComplexNumber operator+(const im& B, const ComplexNumber& A)
{
    return ComplexNumber(A.getReal(), A.getImag() + B);
}

const bool ComplexNumber::operator==(const ComplexNumber& other) const
{
    return real == other.getReal() && imag == other.getImag();
}

const ComplexNumber ComplexNumber::operator*() const
{
    return ComplexNumber(real, -imag);
}

const ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const
{
    cout << "This = " << *this << endl;
    cout << "Other = " << other << endl;
    return ComplexNumber(real * other.getReal() - imag * other.getImag(), real * other.getImag() + imag * other.getReal());
}

im::im(){}

im::im(double v) : value(v) {}

im::operator double() const
{
    return value;
}

}