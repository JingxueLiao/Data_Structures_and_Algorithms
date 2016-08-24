// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

#include "list_node.h"

void ReorderList(ListNode *head) {
    if (head == nullptr)
        return;
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *prev = nullptr, *cur = slow->next;
    slow->next = nullptr;
    while (cur) {
        ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    ListNode *p = head, *q = prev;
    while (q) {
        ListNode *next = q->next;
        q->next = p->next;
        p->next = q;
        p = q->next;
        q = next;
    }
}
