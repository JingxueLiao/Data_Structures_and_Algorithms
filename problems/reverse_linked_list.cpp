// Reverse a singly linked list.

#include "list_node.h"

ListNode *ReverseList(ListNode *head) {
    ListNode *pre = nullptr, *cur = head;
    while (cur) {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
