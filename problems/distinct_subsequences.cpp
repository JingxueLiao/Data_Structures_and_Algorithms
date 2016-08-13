// Given a string S and a string T, count the number of distinct subsequences of T in S.
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// Here is an example:
// S = "rabbbit", T = "rabbit"
// Return 3.

#include <string>
#include <vector>

using namespace std;

int NumDistinct(const string &s, const string &t) {
    vector<int> nums(s.size() + 1, 1);
    for (int i = 0; i < t.size(); ++i) {
        int pre = nums[0];
        nums[0] = 0;
        for (int j = 0; j < s.size(); ++j) {
            int tmp = nums[j + 1];
            nums[j + 1] = nums[j] + (s[j] == t[i] ? pre : 0);
            pre = tmp;
        }
    }
    return nums.back();
}
