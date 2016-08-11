// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
// 
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

#include "tree_node.h"
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ZigzagLevelOrder(const TreeNode *root) {
    if (root == nullptr)
        return vector<vector<int>>();
    vector<const TreeNode *> level{ root };
    vector<vector<int>> traversal;
    bool anti = false;
    while (!level.empty()) {
        vector<const TreeNode *> tmp;
        traversal.push_back(vector<int>(level.size()));
        for (int i = 0; i < level.size(); ++i) {
            traversal.back()[i] = level[i]->val;
            if (level[i]->left)
                tmp.push_back(level[i]->left);
            if (level[i]->right)
                tmp.push_back(level[i]->right);
        }
        swap(level, tmp);
        if (anti)
            reverse(traversal.back().begin(), traversal.back().end());
        anti = !anti;
    }
    return traversal;
}
