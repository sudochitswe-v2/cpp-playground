#include<iostream>
#include<vector>
using namespace std;

struct Tree{
    int data;
    Tree* left;
    Tree* right;
    Tree(int data){
        this->data = data;
        left = right = NULL;
    }
};
Tree* createTree(Tree* root,int data){
    if(root == NULL){
        return new Tree(data);
    }
    if(data < root->data){
        root->left = createTree(root->left,data);
    }
    if(data > root->data){
        root->right = createTree(root->right,data);
    }
    return root;
}
void printTree(Tree* root,vector<string>& output,int level){
    if(root == NULL){
        return;
    }
    if(output.size() == level){
        output.push_back("");
    }
    printTree(root->left,output,level+1);
    output[level] += to_string(root->data) + " ";
    printTree(root->right,output,level+1);
}
void inOrder(Tree* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void preOrder(Tree* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Tree* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void sumOfNodes(Tree* root,int& sum){
    if(root == NULL){
        return;
    }
    sum += root->data;
    sumOfNodes(root->left,sum);
    sumOfNodes(root->right,sum);
}
int main(){
    Tree* root = NULL;
    for(int i=0;i<6;i++){
        int data;
        cin>>data;
        root = createTree(root,data);
    }
    inOrder(root);
    // vector<string> output;
    // printTree(root,output,0);
    // for(const string& s : output){
    //     cout<<s<<endl;
    // }
    int sum = 0;
    sumOfNodes(root,sum);
    cout<<"Sum of all nodes: "<<sum<<endl;
}
