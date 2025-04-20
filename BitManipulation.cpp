#include <iostream>
using namespace std;

// Even or Odd using bitmask
void oddOrEven(int num)
{
    if (!(num & 1))
    {
        cout << "The number is even." << endl;
    }
    else
    {
        cout << "The number is odd." << endl;
    }
}

// Get ith Bit using bitmask
void getIthBit(int num, int i)
{
    int bitMask = 1 << i;
    if (!(num & bitMask))
    {
        cout << "The " << i << "th bit is 0." << endl;
    }
    else
    {
        cout << "The " << i << "th bit is 1." << endl;
    }
}

// Clear ith Bit using bitmask
int clearIthBit(int num, int i)
{
    int bitMask = ~(1 << i);
    return (num & bitMask);
}

// Set ith Bit using bitmask
int setIthBit(int num, int i)
{
    int bitMask = 1 << i;
    return (num | bitMask);
}

// check if n is power of 2 using bitmask
bool isPowerOfTwo(int num)
{
    return (!(num & (num - 1)));
}

// Clear Range of Bits using bitmask
void clearRangeOfBits(int n, int i)
{
    int bitMask = (~0) << i;
    n = n & bitMask;
    cout << "After clearing range of bits: " << n << endl;
}
// Count set Bits
void countSetBits(int num)
{
    int count = 0;
    while (num > 0)
    {
        int lastDigit = num & 1;
        count += lastDigit;
        num = num >> 1;
    }
    cout << "Number of set bits: " << count << endl;
}
// Fast Exponentiations
void fastExpo(int x, int n)
{
    int ans = 1;
    while (n > 0)
    {
        int lastBit = n & 1;
        if (lastBit)
            ans = ans * x;
        x *= x;
        n = n >> 1;
    }
    cout << "Fast Exponentiation: " << ans << endl;
}

int main()
{
    // oddOrEven(5);
    // oddOrEven(6);

    // getIthBit(6, 2);
    // getIthBit(7, 1);

    // cout << setIthBit(6, 3) << endl;

    // cout << clearIthBit(6, 1) << endl;

    // cout << isPowerOfTwo(8) << endl;  // Output: 1
    // cout << isPowerOfTwo(16) << endl; // Output: 1
    // cout << isPowerOfTwo(9) << endl;  // Output: 0

    // clearRangeOfBits(15, 2); // Output: 12

    // countSetBits(15); // Output: 4
    // countSetBits(10); // Output: 2

    fastExpo(2, 10); // Output: 1024
    fastExpo(3, 5);  // Output: 243

    return 0;
}