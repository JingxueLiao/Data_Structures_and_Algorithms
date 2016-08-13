// Given a binary tree, flatten it to a linked list in-place.
// 
// For example,
// Given
// 
//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6

#include "tree_node.h"
#include <stack>

using namespace std;

void Flatten(TreeNode *root) {
    stack<TreeNode *> path;
    if (root)
        path.push(root);
    TreeNode dummy(0);
    TreeNode *pre = &dummy;
    while (!path.empty()) {
        TreeNode *cur = path.top();
        path.pop();
        pre->left = nullptr;
        pre->right = cur;
        pre = cur;
        if (cur->right)
            path.push(cur->right);
        if (cur->left)
            path.push(cur->left);
    }
}
