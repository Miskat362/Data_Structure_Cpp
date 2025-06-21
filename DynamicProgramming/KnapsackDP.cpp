#include <iostream>
#include <vector>
using namespace std;

// 0-1 knapsack problem using Recursion -> O(2^n) time complexity
int knapsackRec(int W, vector<int> wt, vector<int> val, int n) {
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapsackRec(W, wt, val, n - 1);  // exclude
    else
        return max(val[n - 1] + knapsackRec(W - wt[n - 1], wt, val, n - 1),
                   knapsackRec(W, wt, val, n - 1)); // include
}

// Dynamic Programming with Memoization -> O(n * W) time complexity
int knapsackMemo(int W, vector<int> wt, vector<int> val, int n, vector<vector<int>> &dp) {
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];
    if (wt[n - 1] > W)
        return dp[n][W] = knapsackMemo(W, wt, val, n - 1, dp);
    else
        return dp[n][W] = max(val[n - 1] + knapsackMemo(W - wt[n - 1], wt, val, n - 1, dp),
                              knapsackMemo(W, wt, val, n - 1, dp));
}

// Dynamic Programming with Tabulation -> O(n * W) time complexity
int knapsackTab(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] > w)
                dp[i][w] = dp[i - 1][w];
            else
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
        }
    }
    return dp[n][W];
}

int main() {
    int W = 7; // Maximum weight of knapsack
    vector<int> val = {15, 14, 10, 45, 30}; // Values of items
    vector<int> wt = {2, 5, 1, 3, 4}; // Weights of items
    int n = val.size(); // Number of items

    // Using recursion
    cout << "Maximum value in Knapsack (Recursion): " << knapsackRec(W, wt, val, n) << endl;

    // Using Memoization
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    cout << "Maximum value in Knapsack (Memoization): " << knapsackMemo(W, wt, val, n, dp) << endl;

    // Using Tabulation
    cout << "Maximum value in Knapsack (Tabulation): " << knapsackTab(W, wt, val, n) << endl;

    return 0;
}