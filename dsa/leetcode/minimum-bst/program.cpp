
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Solution
{
public:
    int minValue(Node *root)
    {
        // code here
        if (root == nullptr)
            return -1;

        if (root->left == nullptr && root->right == nullptr)
            return root->data;
        else if (root->left == nullptr && root->right != nullptr)
            return root->data;

        minValue(root->left);
    }
};