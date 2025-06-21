#include <iostream>
#include <vector>
using namespace std;

// Dynamic Programming with Tabulation -> O(n * W) time complexity
int knapsackTab(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] > w)
                dp[i][w] = dp[i - 1][w];
            else
                dp[i][w] = max(dp[i][w - wt[i - 1]] + val[i - 1], dp[i - 1][w]);
        }
    }
    return dp[n][W];
}

int main() {
    int W = 7;
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int n = val.size();

    cout << "Maximum value in Knapsack (Tabulation): " << knapsackTab(W, wt, val, n) << endl;

    return 0;
}