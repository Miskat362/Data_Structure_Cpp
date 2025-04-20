#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter n ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j >= 0; j--)
        {
            cout << " ";
        }
        for (int k = i; k <= 2 * i - 1; k++)
        {
            cout << " *";
        }
        cout << endl;
    }
    for (int i = n; i >= 0; i--)
    {
        for (int j = n - i + 1; j >= 0; j--)
        {
            cout << " ";
        }
        for (int k = i + 1; k <= 2 * i - 1; k++)
        {
            cout << " *";
        }
        cout << endl;
    }
}