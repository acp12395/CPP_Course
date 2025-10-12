#include<iostream>
#include<map>
using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person()
    {

    }
    Person(string passingName, int passingAge)
    {
        name = passingName;
        age = passingAge;
    }

    bool operator<(const Person& other) const
    {
        return name < other.name;
    }

    void print() const
    {
        cout<<"Name: " << name << " Age: " << age;
    }
};

int main()
{
    multimap<Person, int> myMap;
    myMap.insert({Person("Alex", 10),1});
    myMap.insert({Person("Alex", 10),2});
    pair<multimap<Person, int>::iterator, multimap<Person, int>::iterator> range = myMap.equal_range(Person("Alex", 10));
    for(multimap<Person, int>::iterator it = range.first; it != range.second; it++)
    {
        it->first.print();
        cout << endl << it->second << endl;
    }
}