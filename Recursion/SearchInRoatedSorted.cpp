#include <iostream>
using namespace std;

int search(int arr[], int si, int ei, int tar)
{
    if (si > ei)
    {
        return -1;
    }
    int mid = si + (ei - si) / 2;
    if (arr[mid] == tar)
    {
        return mid;
    }

    if (arr[si] <= arr[mid])
    { // L1
        if (arr[si] <= tar && tar <= arr[mid])
        {
            return search(arr, si, mid - 1, tar); // left half
        }
        else
        {
            return search(arr, mid + 1, ei, tar); // right half
        }
    }
    else
    { // L2
        if (arr[mid] <= tar && tar <= arr[ei])
        {
            return search(arr, mid + 1, ei, tar); // right half
        }
        else
        {
            return search(arr, si, mid - 1, tar); // left half
        }
    }
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;

    cout << "idx = " << search(arr, 0, n - 1, 0) << endl; // 4

    return 0;
}