// Implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false

#include <string>

using namespace std;

bool IsMatch(const string &s, const string &p) {
    int i = 0, j = 0, pre_i = -1, pre_j = -1;
    while (i < s.size()) {
        if (j < p.size()) {
            if (s[i] == p[j] || p[j] == '?') {
                ++i;
                ++j;
                continue;
            } else if (p[j] == '*') {
                pre_i = i;
                pre_j = j;
                ++j;
                continue;
            }
        }
        if (pre_j == -1)
            return false;
        i = ++pre_i;
        j = pre_j + 1;
    }
    while (j < p.size() && p[j] == '*')
        ++j;
    return i == s.size() && j == p.size();
}
