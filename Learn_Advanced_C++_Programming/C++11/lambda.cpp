#include<iostream>
#include<typeinfo>

using namespace std;

void funcTest(int (*pFunc)())
{
    int retVal = pFunc();
    cout << "Returned " << retVal << endl;
}

class CaptureTest
{
private:
    int a = 1;
    int b = 2;
    template<typename T>
    void executeF(T func)
    {
        cout << "executeF: ";
        func(1,2);
    }
public:
    void test()
    {
        int c = 3;
        int d = 4;

        // Capture local variables by value
        auto pCapture1 = [c,d](int a, int b)
        {
            cout << "Function with local variables captured by value" << endl;
            cout << a << ", " << b << ", " << c << ", " << d << endl;
        };

        pCapture1(a,b);
        executeF(pCapture1);

        // Capture all accesible variables by value and handle them as mutable
        auto pCapture2 = [=]()
        {
            cout << "Function with all accesible variables captured by value, handling them as mutable" << endl;
            cout << a << ", " << b << ", " << c << ", " << d << endl;
        };
        pCapture2();

        // Capture by default all accesible variables by value, handle them as mutable, but only one by reference
        auto pCapture3 = [=,&d]()
        {
            d=5;
            cout << "Function with all accesible variables by default captured by value, handling them as mutable, except one, which is captured by reference" << endl;
            cout << a << ", " << b << ", " << c << ", " << d << endl;
        };
        pCapture3();

        // Capture by default all accesible variables by reference
        auto pCapture4 = [&]()
        {
            cout << "Function with all accesible variables captured by reference" << endl;
            cout << a << ", " << b << ", " << c << ", " << d << endl;
        };
        pCapture4();

        // Capture this
        auto pCapture5 = [this]()
        {
            cout << "Capture all members" << endl;
            cout << a << ", " << b << endl;
            cout << "Local c and d are not accessible" << endl;
        };
        pCapture5();

        // Capture local variables by value and handle them as mutable
        auto pCapture6 = [c,d]() mutable
        {
            cout << "Capture all accesible variables by value and change some value" << endl;
            c = 50;
            cout << c << ", " << d << endl;
        };
        pCapture6();
    }
};

int main()
{
    auto func = [](){cout << "Hello World!" << endl;return 0;};
    cout << "func bare execution: ";
    func();
    cout << "func execution via funcTest: ";
    funcTest(func);
    
    auto pDivide = [](double a, double b) -> double
    {
        if(b == 0.0)
        {
            return INT_MAX;
        }
        return a/b;
    };
    cout << "pDivide execution: ";
    cout << pDivide(4,0) << endl;

    CaptureTest obj;
    obj.test();

    return 0;
}