// Given two binary trees, write a function to check if they are equal or not.
// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

#include "tree_node.h"

bool IsSameTree(const TreeNode *p, const TreeNode *q) {
    if (p == nullptr && q == nullptr)
        return true;
    else if (p == nullptr || q == nullptr)
        return false;
    else
        return p->val == q->val && IsSameTree(p->left, q->left) && IsSameTree(p->right, q->right);
}
