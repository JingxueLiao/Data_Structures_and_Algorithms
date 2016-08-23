// Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
// Return all such possible sentences.

// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
// A solution is ["cats and dog", "cat sand dog"].

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void dfs(vector<string> &breaks, string cur, const vector<vector<int>> &next, const string &s, int begin) {
    if (begin == s.size()) {
        cur.pop_back();
        breaks.push_back(cur);
        return;
    }
    for (auto p = next[begin].begin(); p != next[begin].end(); ++p) {
        dfs(breaks, cur + s.substr(begin, *p - begin) + " ", next , s, *p);
    }
}

vector<string> WordBreak(const string &s, const unordered_set<string> &wordDict) {
    int n = s.size();
    vector<vector<int>> next(n + 1);
    next[n].push_back(n);
    for (int i = n - 1; i >= 0; --i)
        for (int j = n; j > i; --j)
            if (!next[j].empty() && wordDict.find(s.substr(i, j - i)) != wordDict.end())
                next[i].push_back(j);
    vector<string> breaks;
    dfs(breaks, "", next, s, 0);
    return breaks;
}
