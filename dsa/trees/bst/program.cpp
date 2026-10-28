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
    if(data <= root->data){
        root->left = createTree(root->left,data);
    }
    // if(data == root->data){
    //     root->left = createTree(root->left,data);
    // }
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
int sumOfNode(Tree* root){
    if(root == NULL){
        return 0;
    }
    return root->data + sumOfNode(root->left) + sumOfNode(root->right);
}
int sumOfLeafNodes(Tree* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
}
int sumOfNonLeafNodes(Tree* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    return root->data + sumOfNonLeafNodes(root->left) + sumOfNonLeafNodes(root->right);
}
int height(Tree* root){
    if(root == NULL){
        return 0;
    }
    if (root->left == nullptr)
        return height(root->right) + 1;

    if (root->right == nullptr)
        return height(root->left) + 1;
        
    return 1 + max(height(root->left),height(root->right));
}
int main(){
    Tree* root = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        root = createTree(root,data);
    }
    // inOrder(root);
    cout << endl;
    vector<string> output;
    printTree(root,output,0);
    for(const string& s : output){
        cout<<s<<endl;
    }
    int sum = sumOfNode(root);
    cout<<"Sum of all nodes: "<<sum<<endl;
    int leafSum = sumOfLeafNodes(root);
    cout<<"Sum of leaf nodes: "<<leafSum<<endl;
    int nonLeafSum = sumOfNonLeafNodes(root);
    cout<<"Sum of non-leaf nodes: "<<nonLeafSum<<endl;
    int h = height(root);
    cout<<"Height of the tree: "<<h<<endl;
}
