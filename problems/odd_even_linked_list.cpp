// Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

// Example:
// Given 1->2->3->4->5->NULL,
// return 1->3->5->2->4->NULL.

// Note:
// The relative order inside both the even and odd groups should remain as it was in the input. 
// The first node is considered odd, the second node even and so on ...

#include "list_node.h"

ListNode *OddEvenList(ListNode *head) {
    ListNode odd(0), even(0);
    ListNode *p = &odd, *q = &even;
    while (head) {
        p->next = head;
        p = head;
        head = head->next;
        if (head) {
            q->next = head;
            q = head;
            head = head->next;
        }
    }
    p->next = even.next;
    q->next = nullptr;
    return odd.next;
}
