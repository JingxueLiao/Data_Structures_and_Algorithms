// Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.
// Find and return the shortest palindrome you can find by performing this transformation.

// For example:
// Given "aacecaaa", return "aaacecaaa".
// Given "abcd", return "dcbabcd".

#include <string>
#include <vector>

using namespace std;

string ShortestPalindrome(const string &s) {
    if (s.empty())
        return s;
    int n = s.size();
    vector<int> next(n);
    next[0] = -1;
    for (int i = 1; i < n; ++i) {
        int j = next[i - 1];
        while (j != -1 && s[j] != s[i - 1])
            j = next[j];
        next[i] = j + 1;
    }
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[next[i]])
            next[i] = next[next[i]];
    }
    string rs(s.rbegin(), s.rend());
    int i = 0, j = 0;
    while (j + i < n) {
        if (s[i] == rs[j + i]) {
            ++i;
        } else {
            j = j + i - next[i];
            i = next[i];
            if (i == -1)
                i = 0;
        }
    }
    return rs.substr(0, j) + s;
}
