// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

#include "list_node.h"

ListNode *DeleteDuplicates(ListNode *head) {
    ListNode *p = head;
    while (p) {
        ListNode *q = p->next;
        while (q && q->val == p->val) {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        p = q;
    }
    return head;
}
