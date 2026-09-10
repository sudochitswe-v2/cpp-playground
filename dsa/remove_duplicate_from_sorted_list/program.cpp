#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return nullptr;

    ListNode* current = head;
    while (current->next) {
        if (current->val == current->next->val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    return head;
}

int main(){

    // create linked list using a loop
    //head -> 1,2,3,3,5,5,5,5,5,6,8,8,10,10,10,10,10,10,11,11
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 2; i <= 11; i++) {
        if (i == 3 || i == 5 || i == 8 || i == 10 || i == 11) {
            for (int j = 0; j < 5; j++) {
                current->next = new ListNode(i);
                current = current->next;
            }
        } else {
            current->next = new ListNode(i);
            current = current->next;
        }
    }
    // print the linked list
    cout << "Original linked list: ";
    current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    // remove duplicates
    head = deleteDuplicates(head);
    // print the linked list after removing duplicates
    cout << "Linked list after removing duplicates: ";
    current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}