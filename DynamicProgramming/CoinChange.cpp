// leetcode 518
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // Base case: one way to make amount 0

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return dp[amount];
    }
};

// for coins = [1, 2, 5] and amount = 5, ans is 4
// The four combinations are: 1+1+1+1+1, 1+1+1+2, 1+2+2, and 5.