// Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

// Note: The input string may contain letters other than the parentheses ( and ).

// Examples:
// "()())()" -> ["()()()", "(())()"]
// "(a)())()" -> ["(a)()()", "(a())()"]
// ")(" -> [""]

#include <string>
#include <vector>

using namespace std;

void dfs(string s, int pos, int left, int right, vector<string> &result) {
    if (pos == s.size()) {
        if (left == 0 && right == 0)
            result.push_back(s);
        return;
    }
    int next = pos;
    while (next < s.size() && s[next] == s[pos])
        ++next;
    if (s[pos] == '(') {
        for (int i = 0; i <= left && i <= next - pos; ++i)
            dfs(s.substr(0, pos) + s.substr(pos + i), next - i, left - i, right + next - pos - i, result);
    } else if (s[pos] == ')') {
        for (int i = 0; i <= right && i <= next - pos; ++i)
            dfs(s.substr(0, pos) + s.substr(next - i), pos + i, left, right - i, result);
    } else {
        dfs(s, next, left, right, result);
    }
}

vector<string> RemoveInvalidParentheses(const string &s) {
    int left = 0;
    for (auto p = s.begin(); p != s.end(); ++p) {
        if (*p == '(') {
            ++left;
        } else if (*p == ')') {
            left = left == 0 ? 0 : left - 1;
        }
    }
    vector<string> result;
    dfs(s, 0, left, 0, result);
    return result;
}
