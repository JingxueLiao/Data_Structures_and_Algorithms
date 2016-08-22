// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.
 
// For example, given s = "aab",
// Return
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]

#include <vector>
#include <string>

using namespace std;

void dfs(vector<vector<string>> &partitions, vector<string> &cur, const string &s, int begin, const vector<vector<bool>> &is_palindrome) {
    if (begin == s.size()) {
        partitions.push_back(cur);
        return;
    }
    for (int i = begin; i < s.size(); ++i) {
        if (is_palindrome[begin][i]) {
            cur.push_back(s.substr(begin, i - begin + 1));
            dfs(partitions, cur, s, i + 1, is_palindrome);
            cur.pop_back();
        }
    }
}

vector<vector<string>> Partition(const string &s) {
    int n = s.size();
    vector<vector<bool>> is_palindrome(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        is_palindrome[i][i] = true;
    for (int i = 0; i < n - 1; ++i)
        is_palindrome[i][i + 1] = s[i] == s[i + 1];
    for (int i = 2; i < n; ++i)
        for (int j = 0; j < n - i; ++j)
            is_palindrome[j][j + i] = is_palindrome[j + 1][j + i - 1] && s[j] == s[j + i];
    vector<vector<string>> partitions;
    vector<string> cur;
    dfs(partitions, cur, s, 0, is_palindrome);
    return partitions;
}
