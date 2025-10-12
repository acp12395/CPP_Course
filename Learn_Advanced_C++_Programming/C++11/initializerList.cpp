#include<iostream>
#include<initializer_list>

using namespace std;

template<typename T>
class MyList
{
private:
    T* list = nullptr;
    int size;
public:
    MyList(int size) : size(size)
    {
        list = new T[size];
    }
    T& operator[](const int& index)
    {
        return list[index];
    }
    MyList(initializer_list<T> values)
    {
        size = values.size();
        list = new T[size];
        int index = 0;
        for(auto& value : values)
        {
            list[index++] = value;
        }
    }
    void print() const
    {
        for(int index = 0; index < size; index++)
        {
            cout << list[index] << endl;
        }
    }
};

int main()
{
    MyList<int> list{3,4,1};
    list.print();
    MyList<string> listStrings(2);
    listStrings[0] = "Hello ";
    listStrings[1] = "World!";
    listStrings.print();
    return 0;
}