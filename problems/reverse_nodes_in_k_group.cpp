// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
// You may not alter the values in the nodes, only nodes itself may be changed.
// Only constant memory is allowed.

// For example,
// Given this linked list: 1->2->3->4->5
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5

#include "list_node.h"

ListNode *ReverseKGroup(ListNode *head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *cur = &dummy;
    while (cur) {
        ListNode *q = cur->next;
        int i = k;
        while (q && i) {
            q = q->next;
            --i;
        }
        if (i)
            break;
        ListNode *p = cur->next;
        i = k;
        while (i) {
            ListNode *tmp = p->next;
            p->next = q;
            q = p;
            p = tmp;
            --i;
        }
        ListNode *next = cur->next;
        cur->next = q;
        cur = next;
    }
    return dummy.next;
}
