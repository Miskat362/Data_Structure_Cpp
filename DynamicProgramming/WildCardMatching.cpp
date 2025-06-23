// leetCode: 44
// Problem: Wildcard Matching
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isMatch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    
    dp[0][0] = true; // Empty pattern matches empty text

    // Handle patterns with '*' at the beginning
    for (int j = 1; j <= m; j++) {  // Initialize first row
        if (pattern[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pattern[j - 1] == text[i - 1] || pattern[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}

int main() {
    string text = "abcd";
    string pattern = "ab*?";
    // '?' matches any single character
    // '*' matches any sequence of characters (including the empty sequence)

    cout << (isMatch(text, pattern) ? "true" : "false") << endl;

    return 0;
}