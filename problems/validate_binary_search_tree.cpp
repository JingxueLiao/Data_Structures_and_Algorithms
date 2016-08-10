// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 1:
//     2
//    / \
//   1   3
// Binary tree [2,1,3], return true.
// Example 2:
//     1
//    / \
//   2   3
// Binary tree [1,2,3], return false.

#include "tree_node.h"
#include <stack>
#include <climits>

using namespace std;

bool IsValidBST(const TreeNode *root) {
    long long pre = LLONG_MIN;
    stack<const TreeNode *> path;
    const TreeNode *cur = root;
    while (cur || !path.empty()) {
        while (cur) {
            path.push(cur);
            cur = cur->left;
        }
        cur = path.top();
        path.pop();
        if (cur->val <= pre)
            return false;
        pre = cur->val;
        cur = cur->right;
    }
    return true;
}
