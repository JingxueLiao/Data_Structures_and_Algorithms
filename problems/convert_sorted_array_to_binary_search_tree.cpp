// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

#include "tree_node.h"
#include <vector>

using namespace std;

TreeNode *helper(const vector<int> &nums, int begin, int end) {
    if (begin == end)
        return nullptr;
    int mid = begin + (end - begin) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = helper(nums, begin, mid);
    root->right = helper(nums, mid + 1, end);
    return root;
}

TreeNode *SortedArrayToBST(const vector<int> &nums) {
    return helper(nums, 0, nums.size());
}
