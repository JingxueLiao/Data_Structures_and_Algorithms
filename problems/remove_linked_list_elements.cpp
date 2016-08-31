// Remove all elements from a linked list of integers that have value val.

// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5

#include "list_node.h"

ListNode *RemoveElements(ListNode *head, int val) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *p = &dummy;
    while (p->next) {
        if (p->next->val == val) {
            ListNode *next = p->next;
            p->next = next->next;
            delete next;
        } else {
            p = p->next;
        }
    }
    return dummy.next;
}
