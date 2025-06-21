#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Longest common substring using tabulation
int longestCommonSubstring(string str1, string str2) {    // O(n * m) time and space complexity
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLength = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxLength = max(maxLength, dp[i][j]);
            } else {
                dp[i][j] = 0; // Reset to zero for longest common substring
            }
        }
    }
    return maxLength;
}

int main() {
    string str1 = "abcde";
    string str2 = "abgce";

    cout << "Length of Longest Common Substring: " << longestCommonSubstring(str1, str2) << endl;

    return 0;
}