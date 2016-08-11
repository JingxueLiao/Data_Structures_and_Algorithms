// Two elements of a binary search tree (BST) are swapped by mistake.
// Recover the tree without changing its structure.

// Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

#include "tree_node.h"

#include <stack>
#include <algorithm>

using namespace std;

void RecoverTree(TreeNode *root) {
    TreeNode *first = nullptr, *second = nullptr;
    stack<TreeNode *> path;
    TreeNode *cur = root, *pre = nullptr;
    while (cur || !path.empty()) {
        while (cur) {
            path.push(cur);
            cur = cur->left;
        }
        cur = path.top();
        path.pop();
        if (first == nullptr && pre && cur->val < pre->val)
            first = pre;
        if (pre && cur->val < pre->val)
            second = cur;
        pre = cur;
        cur = cur->right;
    }
    if (first && second)
        swap(first->val, second->val);
}
