// Given a linked list, return the node where the cycle begins.
// If there is no cycle, return null.

// Note: Do not modify the linked list.

// Follow up:
// Can you solve it without using extra space?

#include "list_node.h"

ListNode *DetectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    if (fast == nullptr || fast->next == nullptr)
        return nullptr;
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
