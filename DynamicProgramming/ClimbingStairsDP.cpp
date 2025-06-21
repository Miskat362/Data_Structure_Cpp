#include <iostream>
#include <vector>
using namespace std;

// Climbing Stairs problem using Recursion -> O(2^n) time complexity
int climbStairs(int n) {
    if (n <= 1)
        return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

// Dynamic Programming with Memoization -> O(n) time complexity
int climbStairsMemo(int n, vector<int> &dp) {
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    dp[n] = climbStairsMemo(n - 1, dp) + climbStairsMemo(n - 2, dp);
    return dp[n];
}

// Dynamic Programming with Tabulation -> O(n) time complexity
int climbStairsTab(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // 1 way to stay on the ground
    dp[1] = 1; // 1 way to climb one step

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// for climb 1, 2, or 3 steps at a time (Tabulation)
int climbStairsTab2(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // 1 way to stay on the ground
    dp[1] = 1; // 1 way to climb one step
    dp[2] = 2; // 2 ways to climb two steps (1+1 or 2)

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main() {
    int n = 5; // Example number of steps
    
    // Using recursion
    cout << "ways to climb " << n << " steps (recursion): " << climbStairs(n) << endl;
    // Using Memoization
    vector<int> dp(n + 1, -1);
    cout << "ways to climb " << n << " steps (memoization): " << climbStairsMemo(n, dp) << endl;
    // Using Tabulation
    cout << "ways to climb " << n << " steps (tabulation): " << climbStairsTab(n) << endl;

    return 0;
}