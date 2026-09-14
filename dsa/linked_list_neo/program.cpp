#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
} ;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void transverse(Node *&head){
    Node* temp = head;
    while(temp != NULL){
        if(temp->next == NULL)
            cout << temp->data;
        else
            cout << temp->data << "->";
            
        temp = temp->next;
    }
    cout << endl;
}

void insertAtBegining(Node *&head,int data){
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node *&head,int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node *&head,int position,int data){
    if(position == 0){
        insertAtBegining(head,data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = head; int pos = 0;
    while(temp != NULL && pos < position-1){
        temp = temp->next;
        pos++;
    }
    if(temp == NULL){
        cout << "Position out of bounds" << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertSorted(Node *&head, int data){
    Node* newNode = createNode(data);
    if(head == NULL || head->data > data){ // empty list or new node is smaller than head
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL && temp->next->data < data){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int main(){
    //create node using malloc
    Node* head = createNode(10);
    head->next = createNode(20);
    transverse(head);
    insertAtBegining(head,5);
    transverse(head);
    insertAtEnd(head,25);
    transverse(head);
    insertAtPosition(head,2,15);
    transverse(head);
    return 0;
}
