// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
// 
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

#include "tree_node.h"
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> LevelOrderBottom(const TreeNode *root) {
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
    reverse(traversal.begin(), traversal.end());
    return traversal;
}
