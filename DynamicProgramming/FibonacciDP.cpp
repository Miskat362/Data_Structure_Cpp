#include <iostream>
#include <vector>
using namespace std;

// Normal Fibonacci function -> O(2^n) time complexity
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// Dynamic Programming Fibonacci function -> O(n) time complexity with memoization
int fibDp(int n, vector<int> &f) {
    if (n <= 1)
        return n;
    if (f[n] != -1)
        return f[n]; 

    f[n] = fibDp(n - 1, f) + fibDp(n - 2, f);
    return f[n];
}

// Dynamic Programming Fibonacci function -> O(n) time complexity with tabulation
int fibTab(int n) {
    vector<int> f(n + 1, 0);
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    int n = 6;

    // cout << n << " using normal recursion: " << fib(n) << endl;

    // memoization
    vector<int> f(n + 1, -1);
    cout << n << " using dynamic programming: " << fibDp(n, f) << endl;

    // tabulation

    return 0;
}