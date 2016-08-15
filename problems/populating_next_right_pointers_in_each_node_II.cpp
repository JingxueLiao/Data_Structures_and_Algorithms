// Follow up for problem "Populating Next Right Pointers in Each Node".
// 
// What if the given tree could be any binary tree? Would your previous solution still work?
// 
// Note:
// 
// You may only use constant extra space.
// For example,
// Given the following binary tree,
//          1
//        /  \
//       2    3
//      / \    \
//     4   5    7
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \    \
//     4-> 5 -> 7 -> NULL

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : left(nullptr), right(nullptr), next(nullptr) { }
};

void Connect(TreeLinkNode *root) {
    TreeLinkNode *next_level = root;
    while (next_level) {
        TreeLinkNode *cur = next_level, *pre = nullptr;
        next_level = nullptr;
        while (cur) {
            if (cur->left) {
                if (pre)
                    pre->next = cur->left;
                pre = cur->left;
                if (next_level == nullptr)
                    next_level = cur->left;
            }
            if (cur->right) {
                if (pre)
                    pre->next = cur->right;
                pre = cur->right;
                if (next_level == nullptr)
                    next_level = cur->right;
            }
            cur = cur->next;
        }
    }
}
