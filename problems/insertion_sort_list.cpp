// Sort a linked list using insertion sort.

#include "list_node.h"

ListNode *InsertionSortList(ListNode *head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *p = &dummy, *q = head;
    while (q) {
        ListNode *insert = &dummy;
        while (insert->next->val < q->val)
            insert = insert->next;
        if (insert->next != q) {
            p->next = q->next;
            q->next = insert->next;
            insert->next = q;
            q = p->next;
        } else {
            p = q;
            q = q->next;
        }
    }
    return dummy.next;
}
