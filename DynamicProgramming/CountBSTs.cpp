// leetcode problem number: 96
// leetcode problem name: Unique Binary Search Trees
#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1; // Base case: one way to arrange zero nodes

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}

int main() {
    int n = 4;

    cout << "Number of unique BSTs with " << n << " nodes: " << numTrees(n) << endl;

    return 0;
}