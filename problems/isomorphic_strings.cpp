// Given two strings s and t, determine if they are isomorphic.
// Two strings are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters.
// No two characters may map to the same character but a character may map to itself.

// For example,
// Given "egg", "add", return true.
// Given "foo", "bar", return false.
// Given "paper", "title", return true.

// Note:
// You may assume both s and t have the same length.

#include <string>
#include <vector>

using namespace std;

bool IsIsomorphic(const string &s, const string &t) {
    if (s.empty() && t.empty())
        return true;
    if (s.size() != t.size())
        return false;
    vector<char> stot(128, -1), ttos(128, -1);
    for (int i = 0; i < s.size(); ++i) {
        if (stot[s[i]] == -1 && ttos[t[i]] == -1) {
            stot[s[i]] = t[i];
            ttos[t[i]] = s[i];
        } else if (stot[s[i]] != t[i]) {
            return false;
        }
    }
    return true;
}
