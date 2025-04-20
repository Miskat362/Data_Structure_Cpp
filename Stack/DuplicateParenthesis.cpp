#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isDuplicate(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch != ')')
        { // non closing
            s.push(ch);
        }
        else
        { // closing
            if (s.top() == '(')
            {
                return true; // Duplicate
            }
            while (s.top() != '(')
            {
                s.pop();
            }
            s.pop();
        }
    }
    return false; // no duplicate found
}

int main()
{
    string str1 = "((a+b))";       // invalid -> false - 0
    string str2 = "((a+b)+(c+d))"; // valid -> true - 1

    cout << isDuplicate(str1) << endl;
    cout << isDuplicate(str2) << endl;

    return 0;
}