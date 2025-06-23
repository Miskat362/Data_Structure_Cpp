#include <iostream>
#include <vector>
using namespace std;

// nth Catalan number using recursion -> O(2^n) time complexity
int catalanRec(int n) {
    if (n <= 1) 
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += catalanRec(i) * catalanRec(n - 1 - i);
    }
    return res;
}

// nth Catalan number using memoization -> O(n^2) time complexity
int catalanMemo(int n) {
    static vector<int> dp(n + 1, -1);
    if (n <= 1) 
        return 1;
    if (dp[n] != -1) 
        return dp[n];

    int res = 0;
    for (int i = 0; i < n; i++) {
        res += catalanMemo(i) * catalanMemo(n - 1 - i);
    }
    return dp[n] = res;
}

// nth Catalan number using tabulation -> O(n^2) time complexity
int catalanTab(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    return dp[n];
}

int main() {
    int n = 5;

    cout << "The " << n << "th Catalan number is (recursion): " << catalanRec(n) << endl;

    cout << "The " << n << "th Catalan number is (memoization): " << catalanMemo(n) << endl;

    cout << "The " << n << "th Catalan number is (tabulation): " << catalanTab(n) << endl;

    return 0;
}