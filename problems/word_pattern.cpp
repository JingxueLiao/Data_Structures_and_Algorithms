// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.

// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool WordPattern(const string &pattern, const string &str) {
    vector<string> ptos(26);
    unordered_map<string, char> stop;
    int p = 0;
    for (int i = 0; i < pattern.size(); ++i) {
        if (p == str.size())
            return false;
        int j = p;
        while (j < str.size() && str[j] != ' ')
            ++j;
        string s(str.substr(p, j - p));
        p = j == str.size() ? j : j + 1;
        if (ptos[pattern[i] - 'a'].empty() && stop[s] == 0) {
            ptos[pattern[i] - 'a'] = s;
            stop[s] = pattern[i];
        } else if (ptos[pattern[i] - 'a'] != s || stop[s] != pattern[i]) {
            return false;
        }
    }
    return p == str.size();
}
