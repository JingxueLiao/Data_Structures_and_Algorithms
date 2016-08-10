// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.

//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3

#include "tree_node.h"
#include <vector>

using namespace std;

TreeNode *CloneTree(const TreeNode *root) {
    if (root == nullptr)
        return nullptr;
    TreeNode *new_root = new TreeNode(root->val);
    new_root->left = CloneTree(root->left);
    new_root->right = CloneTree(root->right);
    return new_root;
}

vector<TreeNode *> GenerateTrees(int n) {
    if (n <= 0)
        return vector<TreeNode *>();
    vector<vector<vector<TreeNode *>>> trees(n + 1, vector<vector<TreeNode *>>(n + 1));
    for (int i = 1; i <= n; ++i)
        trees[i][i].push_back(new TreeNode(i));
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            for (auto p = trees[j + 1][j + i].begin(); p != trees[j + 1][j + i].end(); ++p) {
                TreeNode *cur = new TreeNode(j);
                cur->right = CloneTree(*p);
                trees[j][j + i].push_back(cur);
            }
            for (int k = j + 1; k < j + i; ++k) {
                for (auto p = trees[j][k - 1].begin(); p != trees[j][k - 1].end(); ++p) {
                    for (auto q = trees[k + 1][j + i].begin(); q != trees[k + 1][j + i].end(); ++q) {
                        TreeNode *cur = new TreeNode(k);
                        cur->left = CloneTree(*p);
                        cur->right = CloneTree(*q);
                        trees[j][j + i].push_back(cur);
                    }
                }
            }
            for (auto p = trees[j][j + i - 1].begin(); p != trees[j][j + i - 1].end(); ++p) {
                TreeNode *cur = new TreeNode(j + i);
                cur->left = CloneTree(*p);
                trees[j][j + i].push_back(cur);
            }
        }
    }
    return trees[1][n];
}
