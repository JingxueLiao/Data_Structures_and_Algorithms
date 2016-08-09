// A message containing letters from A-Z is being encoded to numbers using the following mapping:
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
// The number of ways decoding "12" is 2.

#include <string>

using namespace std;

int NumDecodings(const string &s) {
    if (s.empty() || s[0] == '0')
        return 0;
    int ppre = 1, pre = 1;
    for (int i = 1; i < s.size(); ++i) {
        int cur;
        if (s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2')
                cur = ppre;
            else
                return 0;
        } else if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            cur = ppre + pre;
        } else {
            cur = pre;
        }
        ppre = pre;
        pre = cur;
    }
    return pre;
}
