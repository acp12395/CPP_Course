#include <iostream>
#include <vector>
#include <algorithm>
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
    ~Person()
    {
        name = "";
        age = 0;
    }
    void print()
    {
        cout << "Name: " << name << endl << "Age: " << age;
    }
    friend bool byName(const Person& a, const Person& b);
};

class Dog
{
private:
    string name;
    int age;
public:
    Dog()
    {

    }
    Dog(string passingName, int passingAge)
    {
        name = passingName;
        age = passingAge;
    }
    ~Dog()
    {
        name = "";
        age = 0;
    }
    void print()
    {
        cout << "Name: " << name << endl << "Age: " << age;
    }
    friend bool byAge(const Dog& a, const Dog& b);
};

bool byName(const Person& a, const Person& b) {
    return a.name < b.name;
}
bool byAge(const Dog& a, const Dog& b) {
    return a.age < b.age;
}

int main()
{
    vector<Person> pVec({Person("Wilson",25),Person("Albert", 30),Person("Robert",20)});
    sort(pVec.begin(), pVec.end(), byName);
    for(auto& pers : pVec)
    {
        pers.print();
        cout << endl;
    }

    cout << endl;

    vector<Dog> dVec({Dog("WoofWoof",4),Dog("Peter", 1),Dog("Chummy",2)});
    sort(dVec.begin(), dVec.end(), byAge);
    for(auto& doggie : dVec)
    {
        doggie.print();
        cout << endl;
    }

    return 0;
}