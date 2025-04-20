#include <iostream>
#include <string>
using namespace std;

void printSubsets(string str, string subset)
{
    if (str.length() == 0)
    {
        cout << subset << endl;
        return;
    }
    char ch = str[0];
    // yes choice
    printSubsets(str.substr(1, str.length() - 1), subset + ch);
    // no choice
    printSubsets(str.substr(1, str.length() - 1), subset);
}

int main()
{
    string str = "abc";
    string subset = "";

    printSubsets(str, subset);

    return 0;
}