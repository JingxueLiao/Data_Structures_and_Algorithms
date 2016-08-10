#pragma once

template <typename T>
class BinarySearchTree {
public:
    struct BinarySearchTreeNode {
        T key;
        BinarySearchTreeNode *left;
        BinarySearchTreeNode *right;
        BinarySearchTreeNode *parent;

        BinarySearchTreeNode(const T &k, BinarySearchTreeNode *l = nullptr, BinarySearchTreeNode *r = nullptr, BinarySearchTreeNode *p = nullptr) :
            key(k), left(l), right(r), parent(p) { }
    };

    BinarySearchTree() : root_(nullptr) { }

    BinarySearchTreeNode *Search(const T &key);
    BinarySearchTreeNode *Predecessor(BinarySearchTreeNode *cur);
    BinarySearchTreeNode *Successor(BinarySearchTreeNode *cur);
    void Insert(const T &key);
    void Delete(const T &key);

private:
    BinarySearchTreeNode *root_;

    void Transplant(BinarySearchTreeNode *u, BinarySearchTreeNode *v);
};

template <typename T>
typename::BinarySearchTree<T>::BinarySearchTreeNode *BinarySearchTree<T>::Search(const T &key) {
    BinarySearchTreeNode *cur = root_;
    while (cur) {
        if (key < cur->key) {
            cur = cur->left;
        } else if (cur->key < key) {
            cur = cur->right;
        } else {
            break;
        }
    }
    return cur;
}

template <typename T>
typename::BinarySearchTree<T>::BinarySearchTreeNode *BinarySearchTree<T>::Predecessor(BinarySearchTreeNode *cur) {
    if (cur == nullptr)
        return nullptr;
    if (cur->left) {
        cur = cur->left;
        while (cur->right)
            cur = cur->right;
    } else {
        while (cur->parent && cur != cur->parent->right)
            cur = cur->parent;
        cur = cur->parent;
    }
    return cur;
}

template <typename T>
typename::BinarySearchTree<T>::BinarySearchTreeNode *BinarySearchTree<T>::Successor(BinarySearchTreeNode *cur) {
    if (cur == nullptr)
        return nullptr;
    if (cur->right) {
        cur = cur->right;
        while (cur->left)
            cur = cur->left;
    } else {
        while (cur->parent && cur != cur->parent->left)
            cur = cur->parent;
        cur = cur->parent;
    }
    return cur;
}

template <typename T>
void BinarySearchTree<T>::Insert(const T &key) {
    BinarySearchTreeNode *cur = root_, *parent = nullptr;
    while (cur) {
        parent = cur;
        if (key < cur->key) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    cur = new BinarySearchTreeNode(key);
    if (parent == nullptr) {
        root_ = cur;
    } else {
        if (key < parent->key) {
            parent->left = cur;
        } else {
            parent->right = cur;
        }
        cur->parent = parent;
    }
}

template <typename T>
void BinarySearchTree<T>::Delete(const T &key) {
    BinarySearchTreeNode *node = Search(key);
    if (node == nullptr) {
        return;
    } else if (node->left == nullptr) {
        Transplant(node, node->right);
    } else if (node->right == nullptr) {
        Transplant(node, node->left);
    } else {
        BinarySearchTreeNode *next = Successor(node);
        next->left = node->left;
        next->left->parent = next;
        if (next != node->right) {
            Transplant(next, next->right);
            next->right = node->right;
            next->right->parent = next;
        }
        Transplant(node, next);
    }
    delete node;
}

template <typename T>
void BinarySearchTree<T>::Transplant(BinarySearchTreeNode *u, BinarySearchTreeNode *v) {
    if (u == nullptr)
        return;
    if (u->parent == nullptr) {
        root_ = v;
    } else {
        if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v)
            v->parent = u->parent;
    }
}
