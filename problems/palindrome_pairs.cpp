// Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

// Example 1:
// Given words = ["bat", "tab", "cat"]
// Return [[0, 1], [1, 0]]
// The palindromes are ["battab", "tabbat"]

// Example 2:
// Given words = ["abcd", "dcba", "lls", "s", "sssll"]
// Return [[0, 1], [1, 0], [3, 2], [2, 4]]
// The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool IsPalindrome(const string &word, int begin, int end) {
    while (begin < end) {
        if (word[begin++] != word[--end])
            return false;
    }
    return true;
}

vector<vector<int>> PalindromePairs(const vector<string> &words) {
    vector<vector<int>> pairs;
    unordered_map<string, int> positions;
    for (int i = 0; i < words.size(); ++i)
        positions[words[i]] = i;
    for (int i = 0; i < words.size(); ++i) {
        string cur(words[i].rbegin(), words[i].rend());
        if (positions.find(cur) != positions.end() && positions[cur] != i)
            pairs.push_back(vector<int> { positions[cur], i });
        for (int j = 1; j <= words[i].size(); ++j) {
            if (IsPalindrome(words[i], 0, j)) {
                auto p = positions.find(cur.substr(0, cur.size() - j));
                if (p != positions.end())
                    pairs.push_back(vector<int> { p->second, i });
            }
            if (IsPalindrome(words[i], words[i].size() - j, words[i].size())) {
                auto p = positions.find(cur.substr(j));
                if (p != positions.end())
                    pairs.push_back(vector<int> { i, p->second });
            }
        }
    }
    return pairs;
}
