// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 
// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].

#include "tree_node.h"
#include <vector>
#include <queue>

using namespace std;

vector<int> RightSideView(const TreeNode *root) {
    if (root == nullptr)
        return vector<int>();
    vector<int> view;
    queue<const TreeNode *> level;
    level.push(root);
    while (!level.empty()) {
        int n = level.size();
        const TreeNode *cur;
        while (n--) {
            cur = level.front();
            level.pop();
            if (cur->left)
                level.push(cur->left);
            if (cur->right)
                level.push(cur->right);
        }
        view.push_back(cur->val);
    }
    return view;
}
