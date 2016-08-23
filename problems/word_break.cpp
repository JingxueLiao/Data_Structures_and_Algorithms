// Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
// Return true because "leetcode" can be segmented as "leet code".

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool WordBreak(const string &s, const unordered_set<string> &wordDict) {
    vector<int> breakable(s.size() + 1);
    breakable[0] = true;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            if (breakable[j] && wordDict.find(s.substr(j, i - j + 1)) != wordDict.end()) {
                breakable[i + 1] = true;
                break;
            }
        }
    }
    return breakable[s.size()];
}
