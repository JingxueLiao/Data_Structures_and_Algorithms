// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

#include "tree_node.h"
#include <vector>
#include <stack>

using namespace std;

TreeNode *BuildTree(const vector<int> &inorder, const vector<int> &postorder) {
    if (inorder.empty() || inorder.size() != postorder.size())
        return nullptr;
    int i = inorder.size() - 1, j = postorder.size() - 1;
    TreeNode *head = new TreeNode(postorder[j--]);
    TreeNode *pre = head;
    stack<TreeNode *> path;
    while (j >= 0) {
        TreeNode *cur = new TreeNode(postorder[j--]);
        if (pre->val == inorder[i]) {
            --i;
            while (!path.empty() && path.top()->val == inorder[i]) {
                pre = path.top();
                path.pop();
                --i;
            }
            pre->left = cur;
        } else {
            pre->right = cur;
            path.push(pre);
        }
        pre = cur;
    }
    return head;
}
