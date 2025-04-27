#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int main() {
    int arr[7] = {1, 2, 7, 11, 15, 5, 9};
    int n = 7;
    int target = 9;
    unordered_map<int, int> m;  // key = arr[i], value = i

    for (int i = 0; i < n ; i++) {
        int complement = target - arr[i];
        if (m.count(complement)) {
            cout << m[complement] << " , " << i << endl; // print the indices of the two numbers
            break;
        }
        m[arr[i]] = i;
    }

    return 0;
}