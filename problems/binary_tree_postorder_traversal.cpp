// Given a binary tree, return the postorder traversal of its nodes' values.
 
// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [3,2,1].
 
// Note: Recursive solution is trivial, could you do it iteratively?

#include "tree_node.h"
#include <vector>
#include <stack>

using namespace std;

vector<int> PostorderTraversal(const TreeNode *root) {
    vector<int> traversal;
    stack<const TreeNode *> path;
    const TreeNode *cur = root, *pre = nullptr;
    while (cur || !path.empty()) {
        while (cur) {
            path.push(cur);
            cur = cur->left;
        }
        cur = path.top();
        if (cur->right == nullptr || cur->right == pre) {
            traversal.push_back(cur->val);
            path.pop();
            pre = cur;
            cur = nullptr;
        } else {
            cur = cur->right;
        }
    }
    return traversal;
}
