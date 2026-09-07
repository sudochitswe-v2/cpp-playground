#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    };
};

void basic()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    cout << head->data << "-->";
    cout << head->next->data;
    cout << endl;
};
void printN(Node *head)
{
    Node *temp = head;
    while(temp != NULL){
        if(temp->next == NULL)
            cout << temp->data;
        else
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void insertAtn(Node *&head, int n, int value)
{
    int j = 0;
    Node *temp = head;
    while(j<n){
        temp = temp->next;
        j++;
    }
    Node *newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
    // Node *newNode = new Node(value);
    // if(n == 1)
    // {
    //     newNode->next = head;
    //     head = newNode;
    //     return;
    // }
    // Node *temp = head;
    // for(int i = 1; i < n-1; i++)
    // {
    //     temp = temp->next;
    // }
    // newNode->next = temp->next;
    // temp->next = newNode;
}

void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteAtHead(Node *&head)
{
    if(head == NULL)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteBetween(Node *head,int n){
    int j = 0;
    Node* temp = head;
    while(j<n-1){
        temp = temp->next;
        j++;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void deleteAtTail(Node *head)
{
    Node *temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *nodeToDelete = temp->next;
    temp->next = NULL;
    delete nodeToDelete;
}

void search(Node *head, int key)
{
    Node *temp = head;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            cout << "Found" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found" << endl;
}

void reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void listOfNode(){
    Node *head = NULL;
    Node *tail = NULL;
    int n = 5;
    for(int i = 1; i <= n; i++)
    {
        int x = 0;
        cin >> x;
        Node *newNode = new Node(x);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    // Traversing the linked list
    // Node *temp = head;
    // while(temp != NULL){
    //     if(temp->next == NULL)
    //         cout << temp->data;
    //     else
    //     cout << temp->data << "-->";
    //     temp = temp->next;
    // }
    // cout << endl;
    printN(head);

    // insert at head
    insertAtHead(head, 5);
    printN(head);
}

void sumOfNodes(){
    Node *head=NULL;
    Node *tail=NULL;
    vector<int>ans={10,25,30,60,48,62,50};

    int n=ans.size();
    for(int i=0;i<n;i++){
        int x=ans[i];
       // cin>>x;
        Node *newNode=new Node(x);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;

        }
    }

    //sum of the nodes
    int sum = 0;
    Node *temp = head;
    while(temp != NULL){
        sum += temp->data;
        temp = temp->next;
    }
    cout << "Sum of nodes: " << sum << endl;
    search(head,78);
}

void isPalindrome(Node *head){
    vector<int>ans;
    Node *temp=head;
    while(temp!=NULL){
        ans.push_back(temp->data);
        temp=temp->next;
    }
    int n=ans.size();
    bool isPalindrome=true;
    for(int i=0;i<n/2;i++){
        if(ans[i]!=ans[n-i-1]){
            isPalindrome=false;
            break;
        }
    }
    if(isPalindrome){
        cout<<"The linked list is a palindrome."<<endl;
    }
    else{
        cout<<"The linked list is not a palindrome."<<endl;
    }
}

int main()
{
 
    sumOfNodes();

    return 0;
}