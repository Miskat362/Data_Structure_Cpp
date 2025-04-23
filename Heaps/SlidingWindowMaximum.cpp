#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void maxSlidingWindow(vector<int>& arr, int k) {
    priority_queue<pair<int, int>> pq; // Max heap to store pairs of (element, index)
    
    // first window
    for(int i = 0; i < k; i++) {
        pq.push(make_pair(arr[i], i));
    }

    cout << "Output: " << pq.top().first << " ";

    for (int i = k; i < arr.size(); i++) {
        // Remove elements that are out of the window
        while (!pq.empty() && pq.top().second <= (i - k)) {
            pq.pop();
        }
        // Add the current element to the heap
        pq.push(make_pair(arr[i], i));
        cout << pq.top().first << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3; // Size of the sliding window
    maxSlidingWindow(arr, k); // Output: 3 3 5 5 6 7

    return 0;
}