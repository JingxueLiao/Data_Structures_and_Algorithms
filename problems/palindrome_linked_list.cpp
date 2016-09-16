// Given a singly linked list, determine if it is a palindrome.

// Follow up:
// Could you do it in O(n) time and O(1) space?

#include "list_node.h"

bool IsPalindrome(ListNode *head) {
    if (head == nullptr)
        return true;
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *pre = nullptr, *cur = slow->next;
    slow->next = nullptr;
    while (cur) {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    ListNode *p = head, *q = pre;
    while (q) {
        if (p->val != q->val)
            return false;
        p = p->next;
        q = q->next;
    }
    return true;
}
