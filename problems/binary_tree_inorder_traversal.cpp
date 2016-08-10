// Given a binary tree, return the inorder traversal of its nodes' values.

// For example:
// Given binary tree [1,null,2,3],
//   1
//    \
//     2
//    /
//   3
// return [1,3,2].

// Note: Recursive solution is trivial, could you do it iteratively?

#include "tree_node.h"
#include <vector>
#include <stack>

using namespace std;

vector<int> InorderTraversal(const TreeNode *root) {
    vector<int> traversal;
    stack<const TreeNode *> path;
    const TreeNode *cur = root;
    while (cur || !path.empty()) {
        while (cur) {
            path.push(cur);
            cur = cur->left;
        }
        cur = path.top();
        path.pop();
        traversal.push_back(cur->val);
        cur = cur->right;
    }
    return traversal;
}
