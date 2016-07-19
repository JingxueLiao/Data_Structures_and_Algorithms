// Implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true

#include <string>
#include <vector>

using namespace std;

bool IsMatch(const string &s, const string &p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> match(n + 1, vector<bool>(m + 1));
    match[0][0] = true;
    for (int i = 2; i <= m; i += 2) {
        if (p[i - 1] == '*')
            match[0][i] = true;
        else
            break;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (p[j - 1] != '*') {
                match[i][j] = match[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            } else {
                match[i][j] = match[i][j - 2] || match[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
            }
        }
    }
    return match[n][m];
}
