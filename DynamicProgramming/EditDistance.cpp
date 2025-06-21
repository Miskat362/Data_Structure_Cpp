// leetcode problem number: 72
// leetcode problem title: Edit Distance
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minDistance(string word1, string word2) { // O(n * m) time and space complexity
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) {
                dp[i][j] = j; // If word1 is empty, we need j insertions
            } else if (j == 0) {
                dp[i][j] = i; // If word2 is empty, we need i deletions
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                // 1 + min(deletion, insertion, substitution)
            }
        }
    }

    return dp[n][m];
}

int main() {
    string str1 = "horse";
    string str2 = "ros";

    cout << "Minimum Edit Distance: " << minDistance(str1, str2) << endl;

    return 0;
}