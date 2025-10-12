#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string,int> ages;
    ages["Robert"] = 30;
    cout << "Robert's age = " << ages["Robert"] << endl;
    cout << "map size = " << ages.size() << endl;
    cout << "Sue's age = " << ages["Sue"] << endl;
    cout << "map size = " << ages.size() << endl;
}