#include <iostream>
#include <cstring>
using namespace std;

void toUpper(char word[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] = word[i] - 32;
        }
    }
    cout << word << endl;
    return;
}

int main()
{
    char word[] = "ApPle";

    toUpper(word, strlen(word));

    return 0;
}