#include <iostream>
using namespace std;

class Animal
{
public:
    string color;
    void eat()
    {
        cout << "eats" << endl;
    }
    void breathe()
    {
        cout << "breathes" << endl;
    }
};

class Mammal : public Animal
{
public:
    string bloodType;
    Mammal()
    {
        bloodType = "Warm";
    }
};

class Dog : public Mammal
{
public:
    void tail()
    {
        cout << "a dig has tail" << endl;
    }
};

int main()
{
    Dog d1;

    d1.eat();
    cout << d1.bloodType << endl;
    d1.tail();

    return 0;
}