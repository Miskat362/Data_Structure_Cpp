#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string str)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++) // O(n)
    {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            char top = s.top();
            if (ch == ')' && top == '(' || ch == '}' && top == '{' || ch == ']' && top == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return s.empty(); // all brackets are balanced -> true, else false
}

int main()
{
    string str1 = "([}])";  // invalid -> false - 0
    string str2 = "([{}])"; // valid -> true - 1

    cout << isValid(str1) << endl;
    cout << isValid(str2) << endl;

    return 0;
}