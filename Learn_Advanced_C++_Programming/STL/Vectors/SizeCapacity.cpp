#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    for(int i = 0; i < 3; i++)
    {
        vec.push_back(i);
    }
    cout << vec.size() << endl;
    cout << vec[2] << endl;
    cout << vec.capacity() << endl;
    vec.clear();
    vec.resize(5);
    vec.reserve(4);
    cout << vec.size() << endl;
    cout << vec[2] << endl;
    cout << vec.capacity() << endl;
    return 0;
}