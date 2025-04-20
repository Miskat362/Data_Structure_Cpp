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
// Build a BST from Array
Node* insert(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}
Node* buildBST(int arr[],int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}
void inOrder(Node *root)
{
    if (root == NULL) {
        // cout << -1 << " ";
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
// Search in BST
bool search(Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}
// Delete a node in BST
Node* getInorderSuccessor(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        // root == val
        // Case 1: No child (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        if(root->left == NULL || root->right == NULL) {
            return root->left == NULL ? root->right : root->left;
        }
        // Case 3: Two children
        // Find the inorder successor (smallest in the right subtree)
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = deleteNode(root->right, IS->data);
        return root;
    }
}
// Print in range in BST
void printInRange(Node* root, int start, int end) {
    if (root == NULL) {
        return;
    }
    if (root->data >= start && root->data <= end) {
        cout << root->data << " ";
        printInRange(root->left, start, end);
        printInRange(root->right, start, end);
    } else if (root->data < start) {
        printInRange(root->right, start, end);
    } else {
        printInRange(root->left, start, end);
    }
}
// Root to leaf path
void rootToLeafPath(Node* root, vector<int>& path) {
    if (root == NULL) {
        return;
    }
    path.push_back(root->data);
    if (root->left == NULL && root->right == NULL) {
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        rootToLeafPath(root->left, path);
        rootToLeafPath(root->right, path);
    }
    path.pop_back();
}
// Validate BST
bool isBST(Node* root, int minVal, int maxVal) {
    if (root == NULL) {
        return true;
    }
    if (root->data < minVal || root->data > maxVal) {
        return false;
    }
    return isBST(root->left, minVal, root->data - 1) && isBST(root->right, root->data + 1, maxVal);
}

int main() {
    int arr[] = {5, 1, 3, 4, 2, 7};
    int arr2[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node *root = buildBST(arr2, 9);

    // inOrder(root) << endl; // 1 3 4 5 6 8 10 11 14

    // cout << search(root, 4) << endl; // 1

    // inOrder(root); cout << endl; // 1 3 4 5 6 8 10 11 14
    // deleteNode(root, 5);
    // inOrder(root); cout << endl; // 1 3 4 6 8 10 11 14

    // printInRange(root, 5, 12); cout << endl; // 6 8 10 11

    // vector<int> path;
    // rootToLeafPath(root, path);

    // cout << isBST(root, INT_MIN, INT_MAX) << endl; // 1
    // cout << isBST(root, 1, 14) << endl; // 1

    return 0;
}