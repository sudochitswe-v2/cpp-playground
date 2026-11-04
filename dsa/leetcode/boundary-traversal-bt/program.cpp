#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Given a root of a Binary Tree, return its boundary traversal in the following order:

// Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.
// Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.
// Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.
// Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Solution
{
public:
    bool isLeaf(Node *node)
    {
        return node && !node->left && !node->right;
    }

    void addLeftBoundary(Node *node, vector<int> &ans)
    {
        while (node)
        {
            if (!isLeaf(node))
            {
                ans.push_back(node->data);
            }

            if (node->left)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
    }

    void addLeaves(Node *node, vector<int> &ans)
    {
        if (!node)
            return;

        if (isLeaf(node))
        {
            ans.push_back(node->data);
            return;
        }

        addLeaves(node->left, ans);
        addLeaves(node->right, ans);
    }

    void addRightBoundary(Node *node, vector<int> &ans)
    {
        while (node)
        {
            if (!isLeaf(node))
            {
                ans.push_back(node->data);
            }

            if (node->right)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }
    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> ans;
        if (!root) return ans;

        // Add root if it is not a leaf
        if (!isLeaf(root)) ans.push_back(root->data);

        // 1. Left boundary, excluding leaves
        addLeftBoundary(root->left, ans);

        // 2. All leaf nodes from left to right
        addLeaves(root, ans);

        // 3. Right boundary, excluding leaves, added in reverse order
        vector<int> rightBoundary;
        addRightBoundary(root->right, rightBoundary);

        for (int i = (int)rightBoundary.size() - 1; i >= 0; --i) {
            ans.push_back(rightBoundary[i]);
        }

        return ans;
    }
};