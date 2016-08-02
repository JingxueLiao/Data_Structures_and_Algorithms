// Given a list, rotate the list to the right by k places, where k is non-negative.

// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

#include "list_node.h"

ListNode *RotateRight(ListNode *head, int k) {
    if (head == nullptr || k <= 0)
        return head;
    int size = 0;
    ListNode *p = head, *q = head;
    while (p) {
        ++size;
        p = p->next;
    }
    k %= size;
    if (k == 0)
        return head;
    p = head;
    while (k--)
        p = p->next;
    while (p->next) {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    head = q->next;
    q->next = nullptr;
    return head;
}
