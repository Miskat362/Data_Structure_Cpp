#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to connect ropes with minimum cost
int connectRopes(vector<int>& ropes) {
    // Create a min-heap (priority queue)
    priority_queue<int, vector<int>, greater<int>> minHeap(ropes.begin(), ropes.end());

    int totalCost = 0;

    // While there are more than one rope
    while (minHeap.size() > 1) {
        // Take the two smallest ropes
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        // Connect them and calculate the cost
        int cost = first + second;
        totalCost += cost;

        // Push the new rope back into the heap
        minHeap.push(cost);
    }
    return totalCost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};

    int result = connectRopes(ropes);
    cout << "Minimum cost to connect ropes: " << result << endl;

    return 0;
}

// similar problem on leet code 1000: merge stones 