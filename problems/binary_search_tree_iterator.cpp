// Implement an iterator over a binary search tree (BST).
// Your iterator will be initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.

// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

#include "tree_node.h"
#include <stack>

using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    bool HasNext() {
        return cur || !path.empty();
    }

    int Next() {
        while (cur) {
            path.push(cur);
            cur = cur->left;
        }
        cur = path.top();
        path.pop();
        int tmp = cur->val;
        cur = cur->right;
        return tmp;
    }

private:
    TreeNode *cur;
    stack<TreeNode *> path;
};
