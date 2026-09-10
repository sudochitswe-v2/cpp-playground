#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = head->next;
    ListNode* prev = nullptr;
    while (head && head->next) {
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = second->next;
        second->next = first;
        if (prev) {
            prev->next = second;
        }
        prev = first;
        head = first->next;
    }
    return newHead;
}

int main(){
    // Create a linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head = swapPairs(head);
    return 0;
}