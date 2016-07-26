// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// For "(()", the longest valid parentheses substring is "()", which has length = 2.
// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

#include <string>
#include <vector>

using namespace std;

int LongestValidParentheses(const string &s) {
    vector<int> lengths(s.size() + 1);
    int longest = 0;
    for (int i = 1; i <= s.size(); ++i) {
        if (s[i - 1] == '(')
            continue;
        int j = i - 1 - lengths[i - 1];
        if (j <= 0 || s[j - 1] != '(') {
            lengths[i] = 0;
        } else {
            lengths[i] = i - j + 1 + lengths[j - 1];
        }
        if (longest < lengths[i])
            longest = lengths[i];
    }
    return longest;
}
