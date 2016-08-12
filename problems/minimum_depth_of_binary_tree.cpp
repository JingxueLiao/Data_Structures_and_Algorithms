// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

#include "tree_node.h"
#include <queue>

using namespace std;

int MinDepth(const TreeNode *root) {
    queue<const TreeNode *> level;
    if (root)
        level.push(root);
    int depth = 0;
    while (!level.empty()) {
        ++depth;
        int n = level.size();
        while (n--) {
            const TreeNode *cur = level.front();
            level.pop();
            if (cur->left == nullptr && cur->right == nullptr)
                return depth;
            if (cur->left)
                level.push(cur->left);
            if (cur->right)
                level.push(cur->right);
        }
    }
    return depth;
}
