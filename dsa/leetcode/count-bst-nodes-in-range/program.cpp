// Given a Binary Search Tree (BST) and a range l-h (inclusive), your task is to return the number of nodes in the BST whose value lie in the given range.

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    int getCount(Node *root, int l, int h)
    {
        if (root == nullptr)
            return 0;

        if (root->data >= l && root->data <= h)
            return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
        else if (root->data < l)
            return getCount(root->right, l, h);

        return getCount(root->left, l, h);
    }
};