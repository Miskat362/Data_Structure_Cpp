#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char str[], int n)
{
    int st = 0, end = n - 1;
    bool isPal = true;
    while (st < end)
    {
        if (str[st++] != str[end--])
        {
            cout << "not palindrome" << endl;
            return false;
        }
    }
    cout << "palindrome" << endl;
    return true;
}

int main()
{
    char word[] = "racecar";
    int n = strlen(word);

    isPalindrome(word, n);

    return 0;
}