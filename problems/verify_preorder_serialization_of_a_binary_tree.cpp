// One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
 
//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #

// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 
// Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
 
// Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
 
// You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
 
// Example 1:
// "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Return true
 
// Example 2:
// "1,#"
// Return false
 
// Example 3:
// "9,#,#,1"
// Return false

#include <string>

using namespace std;

bool IsValidSerialization(const string &preorder) {
    if (preorder.empty())
        return false;
    int internal = 0, leaf = 0;
    int i = 0;
    while (i < preorder.size()) {
        if (preorder[i] == '#') {
            ++leaf;
            ++i;
        } else {
            ++internal;
            while (i < preorder.size() && preorder[i] != ',')
                ++i;
        }
        ++i;
        if (leaf > internal && i < preorder.size())
            return false;
    }
    return internal + 1 == leaf;
}
