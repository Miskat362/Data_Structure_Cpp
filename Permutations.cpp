#include <iostream>
#include <string>
using namespace std;

void permutation(string str, string ans)
{
    if (str.empty())
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        string remaining = str.substr(0, i) + str.substr(i + 1);
        permutation(remaining, ans + ch);
    }
}

int main()
{
    string str = "abc";
    string ans = "";

    permutation(str, ans);

    return 0;
}