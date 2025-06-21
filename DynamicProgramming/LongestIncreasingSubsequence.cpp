#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Longest Increasing Subsequence using tabulation
int longestIncreasingSubsequence(vector<int> nums) {    // O(n^2) time and space complexity
    unordered_set<int> s(nums.begin(), nums.end()); // unique
    vector<int> nums2(s.begin(), s.end());
    sort(nums2.begin(), nums2.end());   // ascending order

    // LCS -> LIS
    int n = nums.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (nums[i - 1] == nums2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    vector<int> nums = {50, 3, 10, 7, 40, 80};

    cout << "Length of Longest Increasing Subsequence: " << longestIncreasingSubsequence(nums) << endl;

    return 0;
}