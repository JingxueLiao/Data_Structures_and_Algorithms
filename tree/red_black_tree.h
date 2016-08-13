#pragma once

template <typename T>
class RedBlackTree {
public:
    RedBlackTree();
    ~RedBlackTree();

    void Insert(const T &key);
    void Delete(const T &key);

private:
    enum class Color : char { kRed, kBlack };

    struct RedBlackTreeNode {
        T key;
        Color color;
        RedBlackTreeNode *left;
        RedBlackTreeNode *right;
        RedBlackTreeNode *parent;

        RedBlackTreeNode(const T &k, Color c = Color::kRed, RedBlackTreeNode *l = nullptr, RedBlackTreeNode *r = nullptr, RedBlackTreeNode *p = nullptr) :
            key(k), color(c), left(l), right(r), parent(p) { }
    };

    RedBlackTreeNode *nil_;
    RedBlackTreeNode *root_;
    int size_;

    void LeftRotate(RedBlackTreeNode *node); 
    void RightRotate(RedBlackTreeNode *node);
    void Transplant(RedBlackTreeNode *u, RedBlackTreeNode *v);
    void InsertFixup(RedBlackTreeNode *node);
    void DeleteFixup(RedBlackTreeNode *node);
    void Clear(RedBlackTreeNode *node);
};

template <typename T>
RedBlackTree<T>::RedBlackTree() : nil_(new RedBlackTreeNode(0, Color::kBlack)), root_(nil_), size_(0) {
}

template <typename T>
RedBlackTree<T>::~RedBlackTree() {
    Clear(root_);
    root_ = nil_;
    delete nil_;
}

template <typename T>
void RedBlackTree<T>::Insert(const T &key) {
    RedBlackTreeNode *cur = root_, *parent = nil_;
    while (cur != nil_) {
        parent = cur;
        if (key < cur->key) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    cur = new RedBlackTreeNode(key);
    cur->parent = parent;
    cur->left = nil_;
    cur->right = nil_;
    if (parent == nil_) {
        root_ = cur;
    } else if (key < parent->key) {
        parent->left = cur;
    } else {
        parent->right = cur;
    }
    InsertFixup(cur);
}

template <typename T>
void RedBlackTree<T>::Delete(const T &key) {
    RedBlackTreeNode *cur = root_;
    while (cur != nil_) {
        if (key < cur->key)
            cur = cur->left;
        else if (cur->key < key)
            cur = cur->right;
        else
            break;
    }
    if (cur == nil_)
        return;
    Color original_color = cur->color;
    RedBlackTreeNode *node;
    if (cur->left == nil_) {
        node = cur->right;
        Transplant(cur, node);
    } else if (cur->right == nil_) {
        node = cur->left;
        Transplant(cur, node);
    } else {
        RedBlackTreeNode *next = cur->right;
        while (next->left != nil_)
            next = next->left;
        original_color = next->color;
        node = next->right;
        if (next != cur->right) {
            Transplant(next, next->right);
            next->right = cur->right;
            next->right->parent = next;
        } else {
            node->parent = next;
        }
        next->left = cur->left;
        next->left->parent = next;
        Transplant(cur, next);
        next->color = cur->color;
    }
    if (original_color == Color::kBlack)
        DeleteFixup(node);
}

template <typename T>
void RedBlackTree<T>::LeftRotate(RedBlackTreeNode *node) {
    RedBlackTreeNode *right_child = node->right;
    node->right = right_child->left;
    if (node->right != nil_)
        node->right->parent = node;
    if (node->parent == nil_)
        root_ = right_child;
    else if (node == node->parent->left)
        node->parent->left = right_child;
    else
        node->parent->right = right_child;
    right_child->parent = node->parent;
    right_child->left = node;
    node->parent = right_child;
}

template <typename T>
void RedBlackTree<T>::RightRotate(RedBlackTreeNode *node) {
    RedBlackTreeNode *left_child = node->left;
    node->left = left_child->right;
    if (node->left != nil_)
        node->left->parent = node;
    if (node->parent == nil_)
        root_ = left_child;
    else if (node == node->parent->left)
        node->parent->left = left_child;
    else
        node->parent->right = left_child;
    left_child->parent = node->parent;
    left_child->right = node;
    node->parent = left_child;
}

template <typename T>
void RedBlackTree<T>::Transplant(RedBlackTreeNode *u, RedBlackTreeNode *v) {
    if (u->parent == nil_)
        root_ = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

template <typename T>
void RedBlackTree<T>::InsertFixup(RedBlackTreeNode *node) {
    while (node->parent->color == Color::kRed) {
        RedBlackTreeNode *parent = node->parent;
        RedBlackTreeNode *grandparent = parent->parent;
        if (parent == grandparent->left) {
            RedBlackTreeNode *uncle = grandparent->right;
            if (uncle->color == Color::kRed) {
                parent->color = Color::kBlack;
                uncle->color = Color::kBlack;
                grandparent->color = Color::kRed;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    LeftRotate(parent);
                    node = parent;
                    parent = node->parent;
                }
                RightRotate(grandparent);
                parent->color = Color::kBlack;
                grandparent->color = Color::kRed;
            }
        } else {
            RedBlackTreeNode *uncle = grandparent->left;
            if (uncle->color == Color::kRed) {
                parent->color = Color::kBlack;
                uncle->color = Color::kBlack;
                grandparent->color = Color::kRed;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    RightRotate(parent);
                    node = parent;
                    parent = node->parent;
                }
                LeftRotate(grandparent);
                parent->color = Color::kBlack;
                grandparent->color = Color::kRed;
            }
        }
    }
    root_->color = Color::kBlack;
}

template <typename T>
void RedBlackTree<T>::DeleteFixup(RedBlackTreeNode *node) {
    while (node->color == Color::kBlack && node != root_) {
        RedBlackTreeNode *parent = node->parent;
        if (node == parent->left) {
            RedBlackTreeNode *sibling = parent->right;
            if (sibling->color == Color::kRed) {
                parent->color = Color::kRed;
                sibling->color = Color::kBlack;
                LeftRotate(parent);
                sibling = parent->right;
            }
            if (sibling->left->color == Color::kBlack && sibling->right->color == Color::kBlack) {
                sibling->color = Color::kRed;
                node = parent;
            } else {
                if (sibling->right->color == Color::kBlack) {
                    sibling->left->color = Color::kBlack;
                    sibling->color = Color::kRed;
                    RightRotate(sibling);
                    sibling = parent->right;
                }
                sibling->color = parent->color;
                parent->color = Color::kBlack;
                sibling->right->color = Color::kBlack;
                LeftRotate(parent);
                break;
            }
        } else {
            RedBlackTreeNode *sibling = parent->left;
            if (sibling->color == Color::kRed) {
                parent->color = Color::kRed;
                sibling->color = Color::kBlack;
                RightRotate(parent);
                sibling = parent->left;
            }
            if (sibling->left->color == Color::kBlack && sibling->right->color == Color::kBlack) {
                sibling->color = Color::kRed;
                node = parent;
            } else {
                if (sibling->left->color == Color::kBlack) {
                    sibling->right->color = Color::kBlack;
                    sibling->color = Color::kRed;
                    LeftRotate(sibling);
                    sibling = parent->left;
                }
                sibling->color = parent->color;
                parent->color = Color::kBlack;
                sibling->left->color = Color::kBlack;
                RightRotate(parent);
                break;
            }
        }
    }
    node->color = Color::kBlack;
}

template <typename T>
void RedBlackTree<T>::Clear(RedBlackTreeNode *node) {
    if (node == nil_)
        return;
    Clear(node->left);
    Clear(node->right);
    delete node;
}
