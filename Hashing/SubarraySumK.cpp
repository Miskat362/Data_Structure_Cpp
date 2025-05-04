#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySumK(const vector<int>& arr, int k) {
    unordered_map<int, int> map;    // sum,count
    int ans = 0;
    int sum = 0;

    for (int j = 0; j < arr.size(); j++) {
        sum += arr[j];

        if (sum == k) {
            ans++;
        }
        if (map.count(sum - k)) {
            ans += map[sum - k];
        }
        map[sum]++;
    }
    return ans;
} 

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << "subarrays with sum " << k << ": " << subarraySumK(arr, k) << endl;

    return 0;
}