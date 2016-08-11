// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

#include "tree_node.h"
#include <vector>

using namespace std;

TreeNode *helper(const vector<int> &preorder, int b1, int e1, const vector<int> &inorder, int b2, int e2) {
    if (b1 == e1)
        return nullptr;
    TreeNode *root = new TreeNode(preorder[b1]);
    int i = b2;
    while (inorder[i] != preorder[b1])
        ++i;
    root->left = helper(preorder, b1 + 1, b1 + 1 + i - b2, inorder, b2, i);
    root->right = helper(preorder, b1 + 1 + i - b2, e1, inorder, i + 1, e2);
    return root;
}

TreeNode *BuildTree(const vector<int> &preorder, const vector<int> &inorder) {
    return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}
