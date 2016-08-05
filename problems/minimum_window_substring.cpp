// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, return the empty string "".

// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

#include <string>
#include <vector>

using namespace std;

string MinWindow(const string &s, const string &t) {
    vector<int> need(128), appear(128);
    for (auto p = t.begin(); p != t.end(); ++p)
        ++need[*p];
    int left = t.size();
    int start = 0, len = 0;
    int i = 0, j = 0;
    while (j < s.size()) {
        ++appear[s[j]];
        if (appear[s[j]] <= need[s[j]]) {
            if (--left == 0) {
                while (i <= j) {
                    if (appear[s[i]] == need[s[i]])
                        break;
                    --appear[s[i++]];
                }
                if (len == 0 || j - i + 1 < len) {
                    start = i;
                    len = j - i + 1;
                }
                --appear[s[i]];
                ++i;
                ++left;
            }
        }
        ++j;
    }
    return s.substr(start, len);
}
