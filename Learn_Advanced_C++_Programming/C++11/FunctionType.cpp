#include<iostream>
#include<vector>
#include<functional>

using namespace std;

class FunctorTest
{
public:
    bool operator()(const string& str)
    {
        return (str.size() == 3);
    }
} functor_1;

bool func2(const string& str)
{
    return (str.size() == 3);
}

auto lambda3 = [](const string& str){return (str.size() == 3);};

int test_count(vector<string> vec, function<bool(const string&)> f)
{
    int count = 0;
    for(auto& element : vec)
    {
        if(f(element))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<string> strs{"One", "Two", "Three"};
    cout << "Functor output: " << test_count(strs, functor_1) << endl;
    cout << "Function output: " << test_count(strs, func2) << endl;
    cout << "Lambda output: " << test_count(strs, lambda3) << endl;
    return 0;
}