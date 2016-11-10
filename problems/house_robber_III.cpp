// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
 
// Determine the maximum amount of money the thief can rob tonight without alerting the police.
 
// Example 1:
//      3
//     / \
//    2   3
//     \   \ 
//      3   1
// Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 
// Example 2:
//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1
// Maximum amount of money the thief can rob = 4 + 5 = 9.

#include "tree_node.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<const TreeNode *, int> withRoot;
unordered_map<const TreeNode *, int> withoutRoot;

int IncludeRoot(const TreeNode *root);

int ExcludeRoot(const TreeNode *root) {
    if (root == nullptr)
        return 0;
    if (withoutRoot.find(root) == withoutRoot.end())
        withoutRoot[root] = IncludeRoot(root->left) + IncludeRoot(root->right);
    return withoutRoot[root];
}

int IncludeRoot(const TreeNode *root) {
    if (root == nullptr)
        return 0;
    if (withRoot.find(root) == withRoot.end())
        withRoot[root] = max(root->val + ExcludeRoot(root->left) + ExcludeRoot(root->right), IncludeRoot(root->left) + IncludeRoot(root->right));
    return withRoot[root];
}

int Rob(const TreeNode *root) {
    return max(IncludeRoot(root), ExcludeRoot(root));
}
