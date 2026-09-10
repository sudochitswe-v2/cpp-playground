#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    while (head) {
        if (head->val == val) {
            prev->next = head->next;
        } else {
            prev = head;
        }
        head = head->next;
    }
    return dummy->next;
}
int main(){
    // head = [1,2,6,3,4,5,6], val = 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    head = removeElements(head, 6);

    // Print the modified linked list
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}