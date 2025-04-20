#include <iostream>
using namespace std;

int paring(int n)
{
    if (n == 1 || n == 2)
    {
        return n;
    }
    // single
    int fnm1 = paring(n - 1);
    // pair
    int fnm2 = (n - 1) * paring(n - 2);
    // total
    return fnm1 + fnm2;
}

int main()
{
    cout << "Total pairWays = " << paring(3) << endl;

    return 0;
}