#ifndef template_h__
#define template_h__

#include <iostream>

template<typename T>
class Test
{
private:
    T val;
public:
    Test() {}
    Test(const T& val) : val(val) {}
    void print()
    {
        cout << val << std::endl;
    }
};

#endif