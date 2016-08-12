// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

#include "tree_node.h"
#include "list_node.h"
#include <queue>
#include <stack>

using namespace std;

TreeNode *SortedListToBST(const ListNode *head) {
    if (head == nullptr)
        return nullptr;
    int n = 0;
    const ListNode *p = head;
    while (p) {
        ++n;
        p = p->next;
    }
    TreeNode *root = new TreeNode(0);
    queue<TreeNode *> level;
    level.push(root);
    while (n > 0) {
        TreeNode *cur = level.front();
        level.pop();
        if (--n > 0) {
            cur->left = new TreeNode(0);
            level.push(cur->left);
        }
        if (--n > 0) {
            cur->right = new TreeNode(0);
            level.push(cur->right);
        }
    }
    stack<TreeNode *> path;
    TreeNode *cur = root;
    while (cur || !path.empty()) {
        while (cur) {
            path.push(cur);
            cur = cur->left;
        }
        cur = path.top();
        path.pop();
        cur->val = head->val;
        head = head->next;
        cur = cur->right;
    }
    return root;
}
