// Merge two sorted linked lists and return it as a new list.
// The new list should be made by splicing together the nodes of the first two lists.

#include "list_node.h"

ListNode *MergeTwoSortedLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode *p = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return dummy.next;
}
