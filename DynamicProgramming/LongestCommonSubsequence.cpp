#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcsRec(string str1, string str2) {   // O(2^(n + m)) time complexity, exponential space complexity
    int n = str1.size();
    int m = str2.size();

    if (n == 0 || m == 0) {
        return 0;
    }

    if (str1[n - 1] == str2[m - 1]) {
        return 1 + lcsRec(str1.substr(0, n - 1), str2.substr(0, m - 1));
    } else {
        return max(lcsRec(str1.substr(0, n - 1), str2), lcsRec(str1, str2.substr(0, m - 1)));
    }
}

int lcsMemo(string str1, string str2) {    // O(n * m) time and space complexity
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    if (n == 0 || m == 0) {
        return 0;
    }

    if (dp[n][m] != -1) {
        return dp[n][m];
    }

    if (str1[n - 1] == str2[m - 1]) {
        dp[n][m] = 1 + lcsMemo(str1.substr(0, n - 1), str2.substr(0, m - 1));
    } else {
        dp[n][m] = max(lcsMemo(str1.substr(0, n - 1), str2), lcsMemo(str1, str2.substr(0, m - 1)));
    }

    return dp[n][m];
}

int lcsTabu(string str1, string str2) {    // O(n * m) time and space complexity
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    string str1 = "abcdge";
    string str2 = "abedg";

    cout << "Length of LCS (Recursion) " << lcsRec(str1, str2) << endl;

    cout << "Length of LCS (Memoization) " << lcsMemo(str1, str2) << endl;

    cout << "Length of LCS (Tabulation) " << lcsTabu(str1, str2) << endl;

    return 0;
}