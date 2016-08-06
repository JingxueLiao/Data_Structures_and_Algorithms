// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.

#include "list_node.h"

ListNode *DeleteDuplicates(ListNode *head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *p = &dummy;
    while (p->next) {
        if (p->next->next == nullptr || p->next->val != p->next->next->val) {
            p = p->next;
        } else {
            ListNode *q = p->next;
            int tmp = q->val;
            while (q && q->val == tmp) {
                p->next = q->next;
                delete q;
                q = p->next;
            }
        }
    }
    return dummy.next;
}
