// Given a binary tree, return the preorder traversal of its nodes' values.
 
// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].
 
// Note: Recursive solution is trivial, could you do it iteratively?

#include "tree_node.h"
#include <vector>
#include <stack>

using namespace std;

vector<int> PreorderTraversal(const TreeNode *root) {
    if (root == nullptr)
        return vector<int>();
    vector<int> traversal;
    stack<const TreeNode *> path;
    path.push(root);
    while (!path.empty()) {
        const TreeNode *cur = path.top();
        path.pop();
        traversal.push_back(cur->val);
        if (cur->right)
            path.push(cur->right);
        if (cur->left)
            path.push(cur->left);
    }
    return traversal;
}
