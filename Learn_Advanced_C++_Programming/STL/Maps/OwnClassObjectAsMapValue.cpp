#include<iostream>
#include<map>
#include<unordered_map>
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
        if(name == other.name)
        {
            return this < (Person*)(&other);
        }
        else
        {
            return name < other.name;
        }
    }

    void print() const
    {
        cout<<"Nombre: " << name << " Edad: " << age;
    }
};

int main()
{
    map<Person, int> myMap;
    myMap[Person("Alex", 10)] = 1;
    myMap[Person("Alex", 10)] = 2;
    for(auto it = myMap.begin(); it != myMap.end(); it++)
    {
        it->first.print();
        cout << endl << it->second << endl;
    }
}