#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void buildTree(const vector<int>& nums, int start, int end, int node) { // O(n)
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(nums, start, mid, 2 * node + 1);
        buildTree(nums, mid + 1, end, 2 * node + 2);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int maxQuery(int qi, int qj, int start, int end, int node) { // O(log n)
        if (qi <= start && qj >= end) {
            return tree[node];
        }
        if (qi > end || qj < start) {
            return INT32_MIN; // Return a value that won't affect the max
        }
        int mid = start + (end - start) / 2;
        int leftMax = maxQuery(qi, qj, start, mid, 2 * node + 1);
        int rightMax = maxQuery(qi, qj, mid + 1, end, 2 * node + 2);
        return max(leftMax, rightMax);
    }

    void update(int idx, int value, int start, int end, int node) { // O(log n)
        if (start == end) {
            tree[node] = value;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(idx, value, start, mid, 2 * node + 1);
        } else {
            update(idx, value, mid + 1, end, 2 * node + 2);
        }
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        buildTree(nums, 0, n - 1, 0);
    }

    printTree(){
        for(int el: tree) {
            cout << el << " ";
        }
        cout << endl;
    }

    int rangeQuery(int qi, int qj) {
        return maxQuery(qi, qj, 0, n-1, 0);
    }

    void updateQuery(int idx, int value) {
        return update(idx, value, 0, n - 1, 0);
    }
};
int main() {
    vector<int> nums ={6, 8, -1, 2, 17, 1, 3, 2, 4};

    SegmentTree st(nums);
    st.printTree();

    cout << st.rangeQuery(2, 5) << endl;

    st.updateQuery(3, 10);
    st.printTree();

    return 0;
}