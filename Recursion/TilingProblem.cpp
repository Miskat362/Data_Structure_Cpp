#include <iostream>
using namespace std;

int tiling(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int vertical = tiling(n - 1);   // 2xn-1
    int horizontal = tiling(n - 2); // 2xn-2
    return vertical + horizontal;
}

int main()
{
    cout << tiling(3) << endl;

    return 0;
}