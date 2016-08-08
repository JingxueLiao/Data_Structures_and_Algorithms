// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

#include "list_node.h"

ListNode *partition(ListNode *head, int x) {
    ListNode dummy1(0), dummy2(2);
    ListNode *p = &dummy1, *q = &dummy2;
    while (head) {
        if (head->val < x) {
            p->next = head;
            p = p->next;
        } else {
            q->next = head;
            q = q->next;
        }
        head = head->next;
    }
    q->next = nullptr;
    p->next = dummy2.next;
    return dummy1.next;
}
