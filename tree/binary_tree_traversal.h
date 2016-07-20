#pragma once

#include "tree_node.h"

#include <vector>
#include <stack>

using std::vector;
using std::stack;

template <typename T>
vector<T> PreorderTraversal(const TreeNode<T> *root) {
    vector<T> traversal;
    stack<const TreeNode<T> *> path;
    if (root)
        path.push(root);
    while (!path.empty()) {
        const TreeNode<T> *cur = path.top();
        path.pop();
        traversal.push_back(cur->val);
        if (cur->right)
            path.push(cur->right);
        if (cur->left)
            path.push(cur->left);
    }
    return traversal;
}

template <typename T>
vector<T> InorderTraversal(const TreeNode<T> *root) {
    vector<T> traversal;
    const TreeNode<T> *cur = root;
    stack<const TreeNode<T> *> path;
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

template <typename T>
vector<T> PostorderTraversal(const TreeNode<T> *root) {
    vector<T> traversal;
    const TreeNode<T> *cur = root, *pre = nullptr;
    stack<const TreeNode<T> *> path;
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
