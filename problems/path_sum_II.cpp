// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
// 
// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

#include "tree_node.h"
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &path, vector<int> &cur, const TreeNode *root, int sum) {
    if (root == nullptr)
        return;
    cur.push_back(root->val);
    sum -= root->val;
    if (root->left == nullptr && root->right == nullptr && sum == 0) {
        path.push_back(cur);
    } else {
        dfs(path, cur, root->left, sum);
        dfs(path, cur, root->right, sum);
    }
    cur.pop_back();
}

vector<vector<int>> PathSum(const TreeNode *root, int sum) {
    vector<vector<int>> path;
    vector<int> cur;
    dfs(path, cur, root, sum);
    return path;
}
