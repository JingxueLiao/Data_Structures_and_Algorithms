// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

#include "tree_node.h"
#include <algorithm>

using namespace std;

int MaxDepth(TreeNode *root) {
    return root ? max(MaxDepth(root->left), MaxDepth(root->right)) + 1 : 0;
}
