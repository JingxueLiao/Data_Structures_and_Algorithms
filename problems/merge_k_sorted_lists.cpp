// Merge k sorted linked lists and return it as one sorted list.

#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(nullptr) {}
};

class Compare {
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return b.first < a.first;
    }
};

ListNode *MergeKLists(vector<ListNode *> lists) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> candidates;
    for (int i = 0; i < lists.size(); ++i) {
        if (lists[i]) {
            candidates.push(make_pair(lists[i]->val, i));
            lists[i] = lists[i]->next;
        }
    }
    ListNode dummy(0);
    ListNode *p = &dummy;
    while (!candidates.empty()) {
        pair<int, int> cur = candidates.top();
        candidates.pop();
        p->next = new ListNode(cur.first);
        p = p->next;
        if (lists[cur.second]) {
            candidates.push(make_pair(lists[cur.second]->val, cur.second));
            lists[cur.second] = lists[cur.second]->next;
        }
    }
    return dummy.next;
}
