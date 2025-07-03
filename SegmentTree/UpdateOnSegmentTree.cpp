#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void buildTree(vector<int> &arr, int start, int end, int node) {    // O(n)
        if (start == end) {
            tree[node] = arr[start];
            return;
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, start, mid, 2 * node + 1);
            buildTree(arr, mid + 1, end, 2 * node + 2);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // O(log n)
    int rangeSum(int qi, int qj, int si, int sj, int node) {  // O(log n)
        if (qi > sj || qj < si) {
            return 0;  // No overlap case
        }

        if (qi <= si && qj >= sj) {
            return tree[node];  // Full overlap case
        }
        // Partial overlap case
        int mid = (si + sj) / 2;
        int leftSum = rangeSum(qi, qj, si, mid, 2 * node + 1);
        int rightSum = rangeSum(qi, qj, mid + 1, sj, 2 * node + 2);
        return leftSum + rightSum;
    }

    // O(log n)
    void update(int idx, int value, int start, int end, int node) {
        if (start == end) {
            tree[node] = value;  // Update the leaf node
            return;
        }

        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            // If idx is in the left child
            update(idx, value, start, mid, 2 * node + 1);
        } else {
            // If idx is in the right child
            update(idx, value, mid + 1, end, 2 * node + 2);
        }
        
        // Update the current node after updating the child
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    
public:
    SegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, n - 1, 0);
    }

    int rangeQuery(int qi, int qj) {
        return rangeSum(qi, qj, 0, n - 1, 0);
                        // q1, q2, si, sj, node
    }

    void updateQuery(int idx, int value){
        update(idx, value, 0, n - 1, 0);
    }
};

int main() {
    // Create a segment tree for range sum queries
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    SegmentTree segmentTree(arr);
    segmentTree.updateQuery(1, 3);  // Update index 1 to value 3
    cout << segmentTree.rangeQuery(0, 3) << endl;  // Query sum from index 2 to 5

    return 0;
}