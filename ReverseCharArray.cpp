#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char str[], int n)
{
    int st = 0, end = n - 1;
    while (st < end)
    {
        swap(str[st++], str[end--]);
        // st++;
        // end--;
    }
    cout << "Reversed string: " << str << endl;
}

int main()
{
    char word[] = "code";

    reverseString(word, strlen(word));

    return 0;
}