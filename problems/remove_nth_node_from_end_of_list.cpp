// Given a linked list, remove the nth node from the end of list and return its head.

// For example,
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.

// Note:
// Given n will always be valid.
// Try to do this in one pass.

#include "list_node.h"

ListNode *RemoveNthFromEnd(ListNode *head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *p = &dummy, *q = &dummy;
    while (n--)
        p = p->next;
    while (p->next) {
        p = p->next;
        q = q->next;
    }
    ListNode *tmp = q->next;
    q->next = q->next->next;
    delete tmp;
    return dummy.next;
}
