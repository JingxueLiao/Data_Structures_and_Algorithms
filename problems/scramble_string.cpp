// Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

// Below is one possible representation of s1 = "great":
//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t
// To scramble the string, we may choose any non-leaf node and swap its two children.

// For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that "rgeat" is a scrambled string of "great".

// Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that "rgtae" is a scrambled string of "great".

// Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

#include <string>
#include <vector>

using namespace std;

bool IsScramble(const string &s1, const string &s2) {
    if (s1.size() != s2.size())
        return false;
    if (s1 == s2)
        return true;
    int n = s1.size();
    vector<int> count1(128), count2(128);
    int diff1 = 0, diff2 = 0;
    for (int i = 1; i < n; ++i) {
        if (count1[s1[i - 1]]++ == 0)
            ++diff1;
        if (--count1[s2[i - 1]] == 0)
            --diff1;
        if (diff1 == 0 && IsScramble(s1.substr(0, i), s2.substr(0, i)) && IsScramble(s1.substr(i, n - i), s2.substr(i, n - i)))
            return true;
        if (count2[s1[i - 1]]++ == 0)
            ++diff2;
        if (--count2[s2[n - i]] == 0)
            --diff2;
        if (diff2 == 0 && IsScramble(s1.substr(0, i), s2.substr(n - i, i)) && IsScramble(s1.substr(i, n - i), s2.substr(0, n - i)))
            return true;
    }
    return false;
}
