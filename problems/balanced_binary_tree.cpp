// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

#include "tree_node.h"
#include <algorithm>
#include <cmath>

using namespace std;

int Height(const TreeNode *root) {
    if (root == nullptr)
        return 0;
    int left = Height(root->left);
    int right = Height(root->right);
    return left == -1 || right == -1 || fabs(left - right) > 1 ? -1 : max(left, right) + 1;
}

bool IsBalanced(const TreeNode *root) {
    return Height(root) != -1;
}
