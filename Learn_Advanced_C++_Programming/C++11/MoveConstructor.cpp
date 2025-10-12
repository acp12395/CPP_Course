#include<iostream>

using namespace std;

class Test
{
private:
    int* buffer{nullptr};
    int size;
    void initialize()
    {
        for(int i = 0; i < size; i++)
        {
            buffer[i] = i+1;
        }
    }
public:
    Test()
    {
        cout << "Constructor with no parameters" << endl;
        size = 3;
        buffer = new int[size];
        initialize();
    }
    Test(int size) : size(size)
    {
        cout << "Constructor with size as parameter" << endl;
        buffer = new int[size];
        initialize();
    }
    Test(Test&& other)
    {
        cout << "Move constructor" << endl;
        size = other.size;
        buffer = other.buffer;
        other.buffer = nullptr;
    }
    Test(const Test& other)
    {
        cout << "Copy constructor" << endl;
        size = other.size;
        buffer = new int[size];
        memcpy(buffer, other.buffer,size*sizeof(int));
    }
    Test& operator=(const Test& other)
    {
        cout << "Assignment operator" << endl;
        delete[] buffer;
        size = other.size;
        buffer = new int[size];
        memcpy(buffer, other.buffer,size*sizeof(int));
        return *this;
    }
    Test& operator=(Test&& other)
    {
        cout << "Move asignment operator" << endl;
        delete[] buffer;
        size = other.size;
        buffer = other.buffer;
        other.buffer = nullptr;
        return *this;
    }
    ~Test()
    {
        cout << "Destructor" << endl;
        delete[] buffer;
        buffer = nullptr;
    }
    friend ostream& operator<<(ostream& os, Test& obj);
};

ostream& operator<<(ostream& os, Test& obj)
{
    for(int i = 0; i < obj.size; i++)
    {
        os << obj.buffer[i] << ", ";
    }
    os << "\b\b ";
    return os;
}

int main()
{
    Test A(Test(4));
    cout << A << endl;
    Test B;
    B = A;
    cout << B << endl;
    B = Test();
    cout << B << endl;
    return 0;
}