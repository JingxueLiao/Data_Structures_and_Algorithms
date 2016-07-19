#pragma once

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v = 0, TreeNode *l = nullptr, TreeNode *r = nullptr) : val(v), left(l), right(r) {}
};

vector<int> PreorderTraversal(const TreeNode *root) {
    vector<int> traversal;
    stack<const TreeNode *> path;
    if (root)
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

vector<int> InorderTraversal(const TreeNode *root) {
    vector<int> traversal;
    const TreeNode *cur = root;
    stack<const TreeNode *> path;
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

vector<int> PostorderTraversal(const TreeNode *root) {
    vector<int> traversal;
    const TreeNode *cur = root, *pre = nullptr;
    stack<const TreeNode *> path;
    while (cur || !path.empty()) {
        while (cur) {
            path.push(cur);
            cur = cur->left;
        }
        cur = path.top();
        if (!cur->right || cur->right == pre) {
            path.pop();
            traversal.push_back(cur->val);
            pre = cur;
            cur = nullptr;
        } else {
            cur = cur->right;
        }
    }
    return traversal;
}
