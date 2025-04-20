#include <iostream>
using namespace std;

class Car
{
    string name;
    string color;

public:
    Car()
    {
        cout << "This is non parameterized constructor.." << endl;
    }
    Car(string nameVal, string colorVal)
    {
        name = nameVal;
        color = colorVal;
        cout << "constructor is called" << endl;
    }

    void start()
    {
        cout << "Car has been started.." << endl;
    }
    void stop()
    {
        cout << "Car has been stopped.." << endl;
    }
    // Getters
    string getName()
    {
        return name;
    }
    string getColor()
    {
        return color;
    }
};

int main()
{
    Car c1("BMW", "i8");

    cout << c1.getName() << endl;
    cout << c1.getColor() << endl;

    return 0;
}