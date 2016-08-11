// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
// 
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

#include "tree_node.h"
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> LevelOrder(const TreeNode *root) {
    vector<vector<int>> traversal;
    queue<const TreeNode *> level;
    if (root)
        level.push(root);
    while (!level.empty()) {
        int n = level.size();
        traversal.push_back(vector<int>(n));
        for (int i = 0; i < n; ++i) {
            const TreeNode *cur = level.front();
            level.pop();
            traversal.back()[i] = cur->val;
            if (cur->left)
                level.push(cur->left);
            if (cur->right)
                level.push(cur->right);
        }
    }
    return traversal;
}
