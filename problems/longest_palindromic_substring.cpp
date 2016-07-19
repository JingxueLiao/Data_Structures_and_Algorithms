// Given a string S, find the longest palindromic substring in S.

#include <string>

using namespace std;

string LongestPalindrome(const string &s) {
    int i = 0, n = s.size();
    int start = 0, len = 0;
    while (i < n) {
        int j = i - 1;
        ++i;
        while (i < n && s[i] == s[i - 1])
            ++i;
        int k = i;
        while (j >= 0 && k < n && s[j] == s[k]) {
            --j;
            ++k;
        }
        if (len < k - j - 1) {
            start = j + 1;
            len = k - j - 1;
        }
    }
    return s.substr(start, len);
}
