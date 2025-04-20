#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
    {
        return NULL;
    }
    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);  // left subtree
    currNode->right = buildTree(nodes); // right subtree

    return currNode;
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        // cout << -1 << " ";
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        // cout << -1 << " ";
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        // cout << -1 << " ";
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            if (q.empty())
            {
                break;
            }
            q.push(NULL); // to track next line
        }
        else
        {
            cout << curr->data << " ";

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

int countNode(Node *root)
{
    if (root == NULL)
        return 0;
    int leftCount = countNode(root->left);
    int rightCount = countNode(root->right);
    return leftCount + rightCount + 1;
}

int sumOfNodes(Node *root)
{
    if (root == NULL)
        return 0;
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return root->data + leftSum + rightSum;
}

// Diameter of a tree - longest path between any two nodes
// Approach 1: Using DFS -- O(n^2)
int diam1(Node *root)
{
    if (root == NULL)
        return 0;
    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);
    return max(currDiam, max(leftDiam, rightDiam));
}
// Approach 2 -- O(n)
pair<int, int> diam2(Node *root)
{
    if (root == NULL)
        return make_pair(0, 0);
    pair<int, int> leftInfo = diam2(root->left);   // left diameter, left height
    pair<int, int> rightInfo = diam2(root->right); // right diameter, right height

    int currDiam = leftInfo.second + rightInfo.second + 1;             // current diameter
    int maxDiam = max(currDiam, max(leftInfo.first, rightInfo.first)); // max diameter
    int maxHeight = max(leftInfo.second, rightInfo.second) + 1;        // max height of current node

    return make_pair(maxDiam, maxHeight);
}

// Subtree of another tree
bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->data != root2->data)
        return false;

    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}
bool isSubTree(Node *root, Node *subRoot)
{
    if (root == NULL && subRoot == NULL)
        return true;
    else if (root == NULL || subRoot == NULL)
        return false;

    if (root->data == subRoot->data)
    {
        // identical for subtree
        if (isIdentical(root, subRoot))
            return true;
    }
    int isLeftSubtree = isSubTree(root->left, subRoot);
    if (!isLeftSubtree)
    {
        return isSubTree(root->right, subRoot);
    }

    return true;
}

void topView(Node *root)
{
    queue<pair<Node *, int>> q; // (node,Horizontal Distance)
    map<int, int> m;            // (HD, node->data)

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> curr = q.front();
        q.pop();

        Node *currNode = curr.first;
        int currHD = curr.second;

        if (m.count(currHD) == 0) // HD add in map
        {
            m[currHD] = currNode->data;
        }
        if (currNode->left != NULL)
        {
            pair<Node *, int> left = make_pair(currNode->left, currHD - 1);
            q.push(left);
        }
        if (currNode->right != NULL)
        {
            pair<Node *, int> right = make_pair(currNode->right, currHD + 1);
            q.push(right);
        }
    }
    for (auto it : m)
    {
        cout << it.second << " ";
    }
}

void KthHelper(Node *root, int k, int currLvl)
{
    if (root == NULL)
        return;
    if (currLvl == k)
    {
        cout << root->data << " ";
        return;
    }
    KthHelper(root->left, k, currLvl + 1);
    KthHelper(root->right, k, currLvl + 1);
}
void KthLevel(Node *root, int k)
{
    KthHelper(root, k, 1);
    cout << endl;
}

// Lowest common ancestor --- approach 1 -> O(n),O(n)
bool findPath(Node *root, int n, vector<int> &path)
{
    if (root == NULL)
        return false;

    path.push_back(root->data);
    if (root->data == n)
        return true;

    int isLeft = findPath(root->left, n, path);
    int isRight = findPath(root->right, n, path);

    if (isLeft || isRight)
        return true;

    path.pop_back();
    return false;
}
int LCA(Node *root, int n1, int n2)
{
    vector<int> path1;
    vector<int> path2;

    findPath(root, n1, path1);
    findPath(root, n2, path2);

    int lca = -1;
    for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++)
    {
        if (path1[i] != path2[j])
            return lca;
        lca = path1[i];
    }
    return lca;
}
// Approach 1 -> O(n),O(1)
Node *LCA2(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *leftLCA = LCA2(root->left, n1, n2);
    Node *rightLCA = LCA2(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL)
    {
        return root;
    }
    return leftLCA == NULL ? rightLCA : leftLCA;
}
// Minimum distance between Nodes
int dist(Node *root, int n)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == n)
    {
        return 0;
    }
    int leftDist = dist(root->left, n);
    if (leftDist != -1)
    {
        return leftDist + 1;
    }
    int rightDist = dist(root->right, n);
    if (rightDist != -1)
    {
        return rightDist + 1;
    }
    return -1;
}
int minDist(Node *root, int n1, int n2)
{
    Node *lca = LCA2(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}
// Kth ancestor of a node in a binary tree
int KthAncestor(Node *root, int node, int k)
{
    if (root == NULL)
        return -1;
    if (root->data == node)
        return 0;

    int leftDist = KthAncestor(root->left, node, k);
    int rightDist = KthAncestor(root->right, node, k);

    if (leftDist == -1 && rightDist == -1)
        return -1;

    int validVal = leftDist != -1 ? leftDist : rightDist;
    if (validVal + 1 == k)
    {
        cout << "Kth ancestor : " << root->data << endl;
    }
    return validVal + 1;
}
// Transform to Sum Tree
int transformToSumTree(Node *root)
{
    if (root == NULL)
        return 0;

    int leftOld = transformToSumTree(root->left);
    int rightOld = transformToSumTree(root->right);
    int currOld = root->data;

    root->data = leftOld + rightOld;

    if (root->left != NULL)
        root->data += root->left->data;
    if (root->right != NULL)
        root->data += root->right->data;

    return currOld;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);
    // cout << "root data = " << root->data << endl;

    // preOrder(root);
    // cout << endl;

    // inOrder(root);
    // cout << endl;

    // postOrder(root);
    // cout << endl;

    // levelOrder(root);
    // cout << endl;

    // cout << "Height of the tree is: " << height(root) << endl;

    // cout << "Number of nodes in the tree is: " << countNode(root) << endl;

    // cout << "Sum of nodes in the tree is: " << sumOfNodes(root) << endl;

    // cout << "Diameter of the tree is: " << diam1(root) << endl;

    // cout << "Diameter of the tree (approach 2) is: " << diam2(root).first << endl;

    // Node *subRoot = new Node(2);
    // subRoot->left = new Node(4);
    // subRoot->right = new Node(5);
    // cout << isSubTree(root, subRoot) << endl;

    // topView(root);

    // KthLevel(root, 3);

    // cout << "LCA of 4 and 5 is: " << LCA(root, 4, 5) << endl;

    // cout << "LCA of 4 and 3 is: " << LCA2(root, 4, 3)->data << endl;

    // int n1 = 4, n2 = 6;
    // cout << "Min dist = " << minDist(root, n1, n2);

    // int node = 5, k = 2;
    // KthAncestor(root, node, k);

    transformToSumTree(root);
    levelOrder(root);

    return 0;
}