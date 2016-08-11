// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// 
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
// 
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3

#include "tree_node.h"

bool helper(const TreeNode *r1, const TreeNode *r2) {
    if (r1 == nullptr && r2 == nullptr)
        return true;
    else if (r1 != nullptr || r2 != nullptr)
        return r1->val == r2->val && helper(r1->left, r2->right) && helper(r1->right, r2->left);
    else
        return false;
}

bool IsSymmetric(const TreeNode *root) {
    if (root == nullptr)
        return true;
    return helper(root->left, root->right);
}
