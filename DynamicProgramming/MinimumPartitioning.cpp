#include <iostream>
#include <vector>
using namespace std;

// solve using 0 1 knapsack concept
int getMinDiff(vector<int>nums) {
    int totSum = 0;
    for (int num : nums) {
        totSum += num;
    }

    int n = nums.size();
    int W = totSum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (nums[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], nums[i - 1] + dp[i - 1][j - nums[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int grp1Sum = dp[n][W];
    int grp2Sum = totSum - grp1Sum;
    return abs(grp1Sum - grp2Sum);
}

int main() {
    vector<int> nums ={1, 6, 11, 5};

    cout << "Minimum difference between two subsets: " << getMinDiff(nums) << endl;

    return 0;
}