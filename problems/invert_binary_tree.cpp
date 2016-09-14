// Invert a binary tree.
 
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
 
// to
 
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1
 
#include "tree_node.h"
#include <algorithm>

using namespace std;

TreeNode *InvertTree(TreeNode *root) {
    if (root == nullptr)
        return nullptr;
    swap(root->left, root->right);
    InvertTree(root->left);
    InvertTree(root->right);
    return root;
}
