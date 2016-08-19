// Given a binary tree, find the maximum path sum.
 
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.
 
// For example:
// Given the below binary tree,
// 
//        1
//       / \
//      2   3
// Return 6.

#include "tree_node.h"
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> helper(TreeNode *root) {
    if (root == nullptr)
        return make_pair(0, 0);
    pair<int, int> left = helper(root->left), right = helper(root->right);
    pair<int, int> result = make_pair(root->val, root->val + max(left.second, right.second));
    if (left.second > 0)
        result.first += left.second;
    if (right.second > 0)
        result.first += right.second;
    if (root->left)
        result.first = max(left.first, result.first);
    if (root->right)
        result.first = max(right.first, result.first);
    result.second = max(result.second, 0);
    return result;
}

int MaxPathSum(TreeNode *root) {
    return helper(root).first;
}
