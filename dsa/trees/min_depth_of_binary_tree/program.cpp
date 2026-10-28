// Given a binary tree, find its minimum depth.
//  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    // If left subtree is NULL, recur for right subtree
    if (root->left == nullptr)
        return minDepth(root->right) + 1;

    // If right subtree is NULL, recur for left subtree
    if (root->right == nullptr)
        return minDepth(root->left) + 1;

    // If both left and right subtrees are not NULL, get the minimum of the two depths
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Minimum depth of the binary tree: " << minDepth(root) << endl;

    return 0;
}