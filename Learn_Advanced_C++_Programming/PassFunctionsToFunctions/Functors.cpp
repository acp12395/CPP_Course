#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Test
{
public:
    virtual bool operator()(string str)=0;
};

class MatchTest : public Test
{
private:
    string str;
public:
    MatchTest(string str) : str(str){}
    bool operator()(string incomingStr)
    {
        return str == incomingStr;
    }
};

class SingleCharTest : public Test
{
public:
    SingleCharTest() {}
    bool operator()(string incomingStr)
    {
        return incomingStr.size() == 1;
    }
};

void check(const string& str, Test& test)
{
    cout << test(str) << endl;
}

int main()
{
    
    MatchTest HelloTest("Hello World!");
    SingleCharTest CharTest;
    vector<Test*> tests = {&HelloTest, &CharTest};
    for(auto& test : tests)
    {
        check("Hello World!", *test);
    }
    return 0;
}