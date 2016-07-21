// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <string>
#include <vector>

using namespace std;

void dfs(vector<string> &result, string &cur, int left, int right, char pre) {
    if (left == 0 && right == 0)
        result.push_back(cur);
    if (pre == ')') {
        for (int i = 1; i <= left; ++i) {
            cur.push_back('(');
            dfs(result, cur, left - i, right + i, '(');
        }
        for (int i = 0; i < left; ++i)
            cur.pop_back();
    } else {
        for (int i = 1; i <= right; ++i) {
            cur.push_back(')');
            dfs(result, cur, left, right - i, ')');
        }
        for (int i = 0; i < right; ++i)
            cur.pop_back();
    }
}

vector<string> GenerateParentheses(int n) {
    if (n <= 0)
        return vector<string>();
    vector<string> result;
    string cur;
    dfs(result, cur, n, 0, ')');
    return result;
}
