// Given a complete binary tree, count the number of nodes.

#include "tree_node.h"
#include <stack>

using namespace std;

int CountNodes(const TreeNode *root) {
    if (root == nullptr)
        return 0;
    int lh = 0, rh = 0;
    const TreeNode *cur = root->left;
    while (cur) {
        ++lh;
        cur = cur->left;
    }
    cur = root->right;
    while (cur) {
        ++rh;
        cur = cur->right;
    }
    if (lh == rh)
        return (1 << lh + 1) - 1;
    else
        return CountNodes(root->left) + CountNodes(root->right) + 1;
}
