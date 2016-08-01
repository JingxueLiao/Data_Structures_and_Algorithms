#pragma once

#include <algorithm>

template <typename T>
struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;

    TreeNode (const T &v, TreeNode *l = nullptr, TreeNode *r = nullptr) :
        val(v), left(l), right(r) { }

    TreeNode (T &&v, TreeNode *l = nullptr, TreeNode *r = nullptr) :
        val(std::move(v)), left(l), right(r) { }
};
