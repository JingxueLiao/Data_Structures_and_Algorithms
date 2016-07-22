// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space.
// You may not modify the values in the list, only nodes itself can be changed.

#include "list_node.h"

ListNode *SwapPairs(ListNode *head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *cur = &dummy;
    while (cur->next && cur->next->next) {
        ListNode *p = cur->next, *q = p->next;
        cur->next = q;
        p->next = q->next;
        q->next = p;
        cur = p;
    }
    return dummy.next;
}
