// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of s.

// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int MinCur(const string &s) {
    if (s.empty())
        return 0;
    int n = s.size();
    vector<int> cuts(n + 1, n);
    cuts[0] = -1;
    for (int i = 0; i < n; ++i) {
        int j = i, k = i;
        while (j >= 0 && k < n && s[j] == s[k]) {
            cuts[k + 1] = min(cuts[k + 1], 1 + cuts[j]);
            --j;
            ++k;
        }
        j = i, k = i + 1;
        while (j >= 0 && k < n && s[j] == s[k]) {
            cuts[k + 1] = min(cuts[k + 1], 1 + cuts[j]);
            --j;
            ++k;
        }
    }
    return cuts[n];
}
