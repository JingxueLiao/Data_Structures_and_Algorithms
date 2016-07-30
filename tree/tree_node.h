#pragma once

template <typename T>
struct tree_node {
    T val;
    tree_node *left;
    tree_node *right;

    tree_node(const T &v, tree_node *l = nullptr, tree_node *r = nullptr) : val(v), left(l), right(r) {}
};
