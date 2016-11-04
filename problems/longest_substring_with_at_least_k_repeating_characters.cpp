// Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

// Example 1:

// Input:
// s = "aaabb", k = 3

// Output:
// 3

// The longest substring is "aaa", as 'a' is repeated 3 times.
// Example 2:

// Input:
// s = "ababbc", k = 2

// Output:
// 5

// The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LongestSubstring(const string &s, int begin, int end, int k) {
    if (begin == end)
        return 0;
    vector<int> counts(128);
    for (int i = begin; i < end; ++i)
        ++counts[s[i]];
    bool satisfy = true;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (counts[c] != 0 && counts[c] < k) {
            satisfy = false;
            break;
        }
    }
    if (satisfy) {
        return end - begin;
    } else {
        int longest = 0;
        int i = begin, j = begin;
        while (i < end) {
            while (i < end && counts[s[i]] < k)
                ++i;
            j = i;
            while (j < end && counts[s[j]] >= k)
                ++j;
            longest = max(longest, LongestSubstring(s, i, j, k));
            i = j;
        }
        return longest;
    }
}

int LongestSubstring(const string &s, int k) {
    return LongestSubstring(s, 0, s.size(), k);
}
