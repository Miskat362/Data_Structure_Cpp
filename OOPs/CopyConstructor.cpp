#include <iostream>
using namespace std;

class Car
{
public:
    string name;
    string color;

    Car(string name, string color)
    {
        this->name = name;
        this->color = color;
    }
    Car(Car &original)
    { // custom copy constructor
        cout << "copying original to new..." << endl;
        name = original.name;
        color = original.color;
    }
};

int main()
{
    Car c1("BMW", "black");

    Car c2(c1); // copy c1 to c2
    cout << c2.name << endl;
    cout << c2.color << endl;

    return 0;
}