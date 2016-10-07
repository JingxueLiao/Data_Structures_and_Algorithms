// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 
// Design an algorithm to serialize and deserialize a binary tree.
// There is no restriction on how your serialization/deserialization algorithm should work.
// You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
 
// For example, you may serialize the following tree
//     1
//    / \
//   2   3
//      / \
//     4   5
// as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

#include "tree_node.h"
#include <string>

using namespace std;

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        dfs_serialize(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return dfs_deserialize(data, pos);
    }

private:
    void dfs_serialize(TreeNode *root, string &data) {
        if (root == nullptr) {
            data += "#,";
            return;
        }
        data = data + to_string(root->val) + ",";
        dfs_serialize(root->left, data);
        dfs_serialize(root->right, data);
    }

    TreeNode *dfs_deserialize(const string &data, int &pos) {
        if (data[pos] == '#') {
            pos += 2;
            return nullptr;
        }
        int i = data.find(',', pos);
        TreeNode *cur = new TreeNode(stoi(data.substr(pos, i - pos)));
        pos = i + 1;
        cur->left = dfs_deserialize(data, pos);
        cur->right = dfs_deserialize(data, pos);
        return cur;
    }
};
