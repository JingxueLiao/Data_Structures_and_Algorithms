// Sort a linked list in O(n log n) time using constant space complexity.

#include "list_node.h"

ListNode *SortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *p = head, *q = slow->next;
    slow->next = nullptr;
    p = SortList(p);
    q = SortList(q);
    ListNode dummy(0);
    ListNode *cur = &dummy;
    while (p && q) {
        if (p->val < q->val) {
            cur->next = p;
            p = p->next;
        } else {
            cur->next = q;
            q = q->next;
        }
        cur = cur->next;

    }
    cur->next = p ? p : q;
    return dummy.next;
}
