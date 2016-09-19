// Given a binary tree, return all root-to-leaf paths.
 
// For example, given the following binary tree:
//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:
// ["1->2->5", "1->3"]

#include "tree_node.h"
#include <vector>
#include <string>

using namespace std;

void dfs(const TreeNode *root, string cur, vector<string> &path) {
    cur = cur + "->" + to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) {
        path.push_back(cur.substr(2));
        return;
    }
    if (root->left)
        dfs(root->left, cur, path);
    if (root->right)
        dfs(root->right, cur, path);
}

vector<string> BinaryTreePaths(const TreeNode *root) {
    if (root == nullptr)
        return vector<string>();
    vector<string> path;
    string cur;
    dfs(root, cur, path);
    return path;
}
