#include <iostream>
#include <vector>
using namespace std;

int countMountainRanges(int pairs) {
    vector<int> dp(pairs + 1, 0);
    dp[0] = dp[1] = 1; // Base case: one way to arrange zero or one pair

    for (int i = 2; i <= pairs; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[pairs];
}

int main() {
    int pairs = 3;

    cout << "Number of mountain ranges with " << pairs << " pairs: " << countMountainRanges(pairs) << endl;

    return 0;
}