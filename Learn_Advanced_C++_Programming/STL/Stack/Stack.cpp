#include<iostream>
#include<stack>
#include<string>
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
        cout << "Constructor called" << endl;
    }
    ~Person()
    {
        cout << "Destructor called" << endl;
        name = "";
        age = 0;
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
        cout<<"Name: " << name << " Age: " << age;
    }
};

int main()
{
    stack<Person> myStack;
    myStack.push(Person("Tom", 50));
    myStack.push(Person("Henry", 60));
    Person& personA = myStack.top();
    personA.print();
    myStack.pop();
    personA.print();
    return 0;
}