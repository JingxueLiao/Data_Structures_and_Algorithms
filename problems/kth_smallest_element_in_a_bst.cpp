// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

#include "tree_node.h"
#include <stack>

using namespace std;

int KthSmallest(const TreeNode *root, int k) {
    stack<const TreeNode *> path;
    const TreeNode *cur = root;
    int result;
    while (cur || !path.empty()) {
        while (cur) {
            path.push(cur);
            cur = cur->left;
        }
        cur = path.top();
        path.pop();
        if (--k == 0) {
            result = cur->val;
            break;
        }
        cur = cur->right;
    }
    return result;   
}
