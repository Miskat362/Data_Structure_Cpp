#include <iostream>
#include <vector>
using namespace std;

// Function to check if a subset with the given sum exists
// using dp tabulation
bool isSubsetSum(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (nums[i - 1] > j) {
                dp[i][j] = dp[i - 1][j]; // Exclude the current number
            } else {
                dp[i][j] = max(nums[i-1]+dp[i - 1][j - nums[i - 1]], dp[i - 1][j]); // Include or exclude
            }
        }
    }

    return dp[n][target] == target;
}

int main() {
    vector<int> nums = {4, 2, 7, 1, 3};
    int targetSum = 10;

    cout << isSubsetSum(nums, targetSum) << endl;

    return 0;
}