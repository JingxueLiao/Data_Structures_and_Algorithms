// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.

// Example:
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

#include "list_node.h"

ListNode *AddTwoNumbers(const ListNode *l1, const ListNode *l2) {
    ListNode dump(0);
    ListNode *p = &dump;
    bool carry = false;
    while (l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        ListNode *q = new ListNode(sum % 10);
        p->next = q;
        p = q;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return dump.next;
}
