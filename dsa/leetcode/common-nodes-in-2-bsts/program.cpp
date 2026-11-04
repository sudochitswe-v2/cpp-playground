// Given the roots r1 and r2 of two Binary Search Trees (BST), find all nodes that are present in both trees (the intersection of the two BSTs).

// Return the common node values in sorted order.

// Structure of a Binary Search Tree node
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int> commonNodes;
        stack<Node*> s1, s2;

        while (r1 || !s1.empty() || r2 || !s2.empty()) {
            // Push left subtree of r1
            while (r1) {
                s1.push(r1);
                r1 = r1->left;
            }
            // Push left subtree of r2Your program took more time than expected.

            while (r2) {
                s2.push(r2);
                r2 = r2->left;
            }

            // If either stack is empty, no more common elements can exist
            if (s1.empty() || s2.empty()) {
                break;
            }

            Node* top1 = s1.top();
            Node* top2 = s2.top();

            if (top1->data == top2->data) {
                commonNodes.push_back(top1->data);
                s1.pop();
                s2.pop();
                r1 = top1->right;
                r2 = top2->right;
            } else if (top1->data < top2->data) {
                s1.pop();
                r1 = top1->right;
            } else {
                s2.pop();
                r2 = top2->right;
            }
        }

        return commonNodes;
    }
     bool isExist(Node* root, int key) {
            if (!root) return false;
            if (root->data == key) return true;
            if (key < root->data) return isExist(root->left, key);
            return isExist(root->right, key);
        }
        void inorderTraversal(Node* r1, Node* r2, vector<int>& commonNodes) {
            if (!r1 || !r2) return;

            inorderTraversal(r1->left, r2, commonNodes);

            if (isExist(r2, r1->data)) {
                commonNodes.push_back(r1->data);
            }

            inorderTraversal(r1->right, r2, commonNodes);
        }
        vector<int> findCommon(Node* r1, Node* r2) {
            vector<int> commonNodes;
            inorderTraversal(r1, r2, commonNodes);
            return commonNodes;        
        }
};