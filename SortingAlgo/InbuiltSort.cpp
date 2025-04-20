#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1, 4, 1, 3, 2, 4, 3, 7};
    sort(arr, arr + 8);

    // descending order
    // sort(arr, arr + 8, greater<int>());

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}