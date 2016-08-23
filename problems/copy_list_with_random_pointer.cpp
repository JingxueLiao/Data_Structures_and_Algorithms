// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
// Return a deep copy of the list.

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) { }
};

RandomListNode *CopyRandomList(RandomListNode *head) {
    if (head == nullptr)
        return nullptr;
    RandomListNode *p = head, *q;
    while (p) {
        q = new RandomListNode(p->label);
        q->next = p->next;
        p->next = q;
        p = q->next;
    }
    p = head;
    while (p) {
        q = p->next;
        if (p->random)
            q->random = p->random->next;
        p = q->next;
    }
    RandomListNode *copy = head->next;
    p = head;
    while (p) {
        q = p->next;
        p->next = q->next;
        q->next = p->next ? p->next->next : nullptr;
        p = p->next;
    }
    return copy;
}

int main() {
    RandomListNode *p = new RandomListNode(-1);
    CopyRandomList(p);
    return 0;
}
