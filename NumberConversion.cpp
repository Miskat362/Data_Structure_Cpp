#include <iostream>
using namespace std;

void binToDec(int binNum)
{
    int n = binNum;
    int decNum = 0;
    int pow = 1;
    while (n > 0)
    {
        int lastDig = n % 10;
        decNum += lastDig * pow;
        pow = pow * 2;
        n = n / 10;
    }
    cout << "Decimal of " << binNum << " is: " << decNum << endl;
}

void DecToBin(int decNum)
{
    int n = decNum;
    int pow = 1;
    int binNum = 0;
    while (n > 0)
    {
        binNum += (n % 2) * pow;
        n = n / 2;
        pow = pow * 10;
    }
    cout << "Binary of " << decNum << " is: " << binNum << endl;
}

int main()
{
    binToDec(1001);
    DecToBin(4);

    return 0;
}