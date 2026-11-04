#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// min absoluate difference of bst
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 


class Solution {
  public:
    void inorder(Node* root,vector<int> &nums){
        if(!root) return;
        inorder(root->left,nums);
        nums.push_back(root->data);
        inorder(root->right,nums);
        return;
    }
    int absDiff(Node *root) {
        vector<int> nums;
        inorder(root,nums);
        int size = nums.size();
        int ans = INT_MAX;
        
        for(int i=0;i<size-1;i++){
            ans = min(ans,nums[i+1]-nums[i]);
        }
        return ans;
    }
};