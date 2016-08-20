// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.
 
// For example,
//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Return the sum = 12 + 13 = 25.

#include "tree_node.h"

int dfs(const TreeNode *root, int cur) {
    if (root == nullptr)
        return 0;
    cur = cur * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr)
        return cur;
    return dfs(root->left, cur) + dfs(root->right, cur);
}

int SumNumbers(const TreeNode *root) {
    return dfs(root, 0);
}
