// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.

#include <string>
#include <vector>

using namespace std;

bool IsInterleave(const string &s1, const string &s2, const string &s3) {
    if (s1.size() + s2.size() != s3.size())
        return false;
    int n = s1.size(), m = s2.size();
    vector<bool> satisfy(m + 1);
    satisfy[0] = true;
    for (int i = 1; i <= m; ++i) {
        if (s2[i - 1] == s3[i - 1]) {
            satisfy[i] = true;
        } else {
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        satisfy[0] = satisfy[0] && s1[i - 1] == s3[i - 1];
        for (int j = 1; j <= m; ++j)
            satisfy[j] = satisfy[j] && s1[i - 1] == s3[i + j - 1] || satisfy[j - 1] && s2[j - 1] == s3[i + j - 1];
    }
    return satisfy[m];
}
