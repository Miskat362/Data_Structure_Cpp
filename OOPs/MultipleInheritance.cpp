#include <iostream>
using namespace std;

class Teacher
{
public:
    int salary;
    string subject;
};

class Student
{
public:
    int roll;
    float cgpa;
};

class TA : public Teacher, public Student
{
public:
    string name;
};

int main()
{
    TA ta1;
    ta1.name = "Miskat Ahmmed";
    ta1.subject = "C++";
    ta1.cgpa = 9.7;

    cout << ta1.name << endl;
    cout << ta1.subject << endl;
    cout << ta1.cgpa << endl;

    return 0;
}