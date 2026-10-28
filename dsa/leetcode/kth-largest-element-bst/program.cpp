
// Given the root of a Binary Search Tree (BST) and an integer k, find the k-th largest element in the BST without modifying its structure.
#include <iostream>
using namespace std;
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

int findLarge(Node *root, int &k)
{   int result = -1;
    if (root == nullptr)
        return result;
    findLarge(root->right, k);
    k--;
    if (k == 0)
    {
        result = root->data;
        return;
    }
    findLarge(root->left, k);
}
int kthLargest(Node *root, int k)
{
    // code here
    int result = findLarge(root, k);
    return result;
}

int main()
{
    return 0;
}