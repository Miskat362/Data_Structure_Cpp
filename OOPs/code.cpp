#include <iostream>
using namespace std;

class Student
{
    string name;
    float cgpa;

public:
    void getPercentage()
    {
        cout << (cgpa * 10) << "%" << endl;
    }
    // Setters
    void setName(string nameVal)
    {
        name = nameVal;
    }
    void setCGPA(float cgpaVal)
    {
        cgpa = cgpaVal;
    }
    // getters
    string getName()
    {
        return name;
    }
    float getCGPA()
    {
        return cgpa;
    }
};
int main()
{
    Student s1;
    s1.setName("Miskat");
    s1.setCGPA(9.8);

    cout << s1.getName() << endl;
    cout << s1.getCGPA() << endl;
    return 0;
}