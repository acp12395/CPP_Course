#include <iostream>

using namespace std;

class Animal
{
protected:
    string name;
public:
    virtual string getSound()=0;
    virtual void move()=0;
};

class Dog : public Animal
{
public:
    string getSound()
    {
        return "bark";
    }
};

class Chihuahua : public Dog
{
public:
    Chihuahua(string givenName)
    {
        name = "Chihuahua " + givenName;
    }
    void move()
    {
        cout << name << ": runs with little steps while " << getSound() << "ing" << endl;
    }
};

class GreatDane : public Dog
{
public:
    GreatDane(string givenName)
    {
        name = "Great Dane " + givenName;
    }
    void move()
    {
        cout << name << ": runs with long steps while " << getSound() << "ing" << endl;
    }
};

class Cat : public Animal
{
public:
    string getSound()
    {
        return "meow";
    }
};

class Cheetah : public Cat
{
public:
    Cheetah(string givenName)
    {
        name = "Cheetah " + givenName;
    }
    void move()
    {
        cout << name << ": runs super fast while " << getSound() << "ing" << endl;
    }
};

class DomesticCat : public Cat
{
public:
    DomesticCat(string givenName)
    {
        name = "Cat " + givenName;
    }
    void move()
    {
        cout << name << ": runs fast while " << getSound() << "ing" << endl;
    }
};

int main()
{
    Cheetah Orion("Orion");
    DomesticCat Sabrina("Sabrina");
    Chihuahua Lucas("Lucas");
    GreatDane Roman("Roman");
    Animal* animals[4] = {&Orion, &Sabrina, &Lucas, &Roman};
    for(int i = 0; i < sizeof(animals); i++)
    {
        animals[i]->move();
    }
    return 0;
}