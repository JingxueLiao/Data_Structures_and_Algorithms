// Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,

// return 1->4->3->2->5->NULL.

// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

#include "list_node.h"

ListNode *ReverseBetween(ListNode *head, int m, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *start = &dummy;
    for (int i = 1; i < m; ++i)
        start = start->next;
    ListNode *p = start->next, *q = nullptr;
    for (int i = m; i <= n; ++i) {
        ListNode *tmp = p->next;
        p->next = q;
        q = p;
        p = tmp;
    }
    start->next->next = p;
    start->next = q;
    return dummy.next;
}
