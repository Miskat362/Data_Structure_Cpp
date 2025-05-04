#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int largestZeroSumSubarray(const vector<int>& arr) {
    unordered_map<int, int> map;
    int ans = 0;
    int sum = 0;

    for (int j = 0; j < arr.size(); j++) {
        sum += arr[j];

        if (map.count(sum)) {
            int currLen = j - map[sum]; // j-idx
            ans = max(ans, currLen);
        } else {
            map[sum] = j; // Store the first occurrence of the sum
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};

    cout << "largest subarray with sum 0: " << largestZeroSumSubarray(arr) << endl;

    return 0;
}