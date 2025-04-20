#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};
// Build a BST from sorted array
Node* BSTfromSortedVec(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end-start) / 2;
    Node* root = new Node(arr[mid]);
    root->left = BSTfromSortedVec(arr, start, mid - 1);
    root->right = BSTfromSortedVec(arr, mid + 1, end);
    return root;
}

void preOrder(Node *root) {
    if (root == NULL) {
        // cout << -1 << " ";
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// BST to Balanced BST
Node* BSTfromSortedVec(vector<int> arr, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end-start) / 2;
    Node* root = new Node(arr[mid]);
    root->left = BSTfromSortedVec(arr, start, mid - 1);
    root->right = BSTfromSortedVec(arr, mid + 1, end);
    return root;
}
void getInorder(Node* root, vector<int>& nodes) {
    if (root == NULL) {
        return;
    }
    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}
Node* balanceBST(Node* root) {
    // Step 1: get inorder sequence of the BST
    vector<int> nodes;
    getInorder(root, nodes);
    // Step 2: build a balanced BST from the sorted array
    return BSTfromSortedVec(nodes, 0, nodes.size() - 1);
}

// Q: Largest BST in a Binary Tree
class Info {
public:
    bool isBST;
    int min;
    int max;
    int sz;
    Info(bool isBST, int min, int max, int sz) {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->sz = sz;
    }
};

static int maxSize;

Info* largestBST(Node* root) {
    if (root == NULL) {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }
    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));
    int currSz = leftInfo->sz + rightInfo->sz + 1;

    if(leftInfo->isBST && rightInfo->isBST && leftInfo->max < root->data && rightInfo->min > root->data) {
        maxSize = max(maxSize, currSz);
        return new Info(true, currMin, currMax, currSz);
    } else {
        return new Info(false, 0, 0, 0);
    }
}

// Q: Merge two BSTs
Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;
    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    int i = 0, j = 0;
    while (i < nodes1.size() && j < nodes2.size()) {
        if (nodes1[i] < nodes2[j]) {
            merged.push_back(nodes1[i]);
            i++;
        } else {
            merged.push_back(nodes2[j]);
            j++;
        }
    }
    while (i < nodes1.size()) {
        merged.push_back(nodes1[i]);
        i++;
    }
    while (j < nodes2.size()) {
        merged.push_back(nodes2[j]);
        j++;
    }
    return BSTfromSortedVec(merged, 0, merged.size() - 1);
}

int main()
{
    // int arr[] = {3, 4, 5, 6, 7, 8, 9};
    // Node* root = BSTfromSortedVec(arr, 0, 6);
    // preOrder(root); cout << endl; // 6 4 3 5 8 7 9

    // Q: BST to Balanced BST
    // Node* root = new Node(6);
    // root->left = new Node(5);
    // root->left->left = new Node(4);
    // root->left->left->left = new Node(3);

    // root->right = new Node(7);
    // root->right->right = new Node(8);
    // root->right->right->right = new Node(9);

    // preOrder(root); cout << endl; // 6 5 4 3 7 8 9
    // root = balanceBST(root);
    // preOrder(root); cout << endl; // 6 4 3 5 8 7 9

    // Q: Largest BST in a Binary Tree
    // Node* root = new Node(50);
    // root->left = new Node(30);  
    // root->left->left = new Node(5);
    // root->left->right = new Node(20);

    // root->right = new Node(60);
    // root->right->left = new Node(45);
    // root->right->right = new Node(70);
    // root->right->right->left = new Node(65);
    // root->right->right->right = new Node(80);

    // largestBST(root);
    // cout << "Size of largest BST is: " << maxSize << endl; // 5

    //Q: Merge two BSTs
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* mergedRoot = mergeBSTs(root1, root2);
    preOrder(mergedRoot); cout << endl; // 3 1 2 9 4 12

    return 0;
}