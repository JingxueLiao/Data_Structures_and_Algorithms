#pragma once

#include "tree_node.h"

#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

template <typename T>
vector<T> PreorderTraversal(TreeNode<T> *root) {
    vector<T> traversal;
    TreeNode<T> *cur = root;
    while (cur) {
        if (cur->left == nullptr) {
            traversal.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode<T> *pre = cur->left;
            while (pre->right && pre->right != cur)
                pre = pre->right;
            if (pre->right == nullptr) {
                traversal.push_back(cur->val);
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                cur = cur->right;
            }
        }
    }
    return traversal;
}

template <typename T>
vector<T> InorderTraversal(TreeNode<T> *root) {
    vector<T> traversal;
    TreeNode<T> *cur = root;
    while (cur) {
        if (cur->left == nullptr) {
            traversal.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode<T> *pre = cur->left;
            while (pre->right && pre->right != cur)
                pre = pre->right;
            if (pre->right == nullptr) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                traversal.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return traversal;
}

template <typename T>
vector<T> PostorderTraversal(TreeNode<T> *root) {
    vector<T> traversal;
    TreeNode<T> dummy(0);
    dummy.left = root;
    TreeNode<T> *cur = &dummy;
    while (cur) {
        if (cur->left == nullptr) {
            cur = cur->right;
        } else {
            TreeNode<T> *pre = cur->left;
            while (pre->right && pre->right != cur)
                pre = pre->right;
            if (pre->right == nullptr) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                int n = traversal.size();
                TreeNode<T> *p = cur->left;
                while (p) {
                    traversal.push_back(p->val);
                    p = p->right;
                }
                reverse(traversal.begin() + n, traversal.end());
                cur = cur->right;
            }
        }
    }
    return traversal;
}
