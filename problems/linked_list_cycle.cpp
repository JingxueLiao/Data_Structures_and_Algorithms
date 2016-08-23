// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?

#include "list_node.h"

bool HasCycle(const ListNode *head) {
    const ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}
