// You are given a string, s, and a list of words, words, that are all of the same length.
// Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

// For example, given:
// s: "barfoothefoobarman"
// words: ["foo", "bar"]

// You should return the indices: [0,9].

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

vector<int> FindSubstring(const string &s, const vector<string> &words) {
    if (words.empty())
        return vector<int>();
    vector<int> substrings;
    unordered_map<string, int> keys;
    for (auto p = words.begin(); p != words.end(); ++p)
        ++keys[*p];
    unordered_map<string, int> appeared;
    int word_length = words[0].size();
    int n = s.size(), m = words.size();
    for (int i = 0; i < word_length; ++i) {
        int start = i;
        appeared.clear();
        for (int j = i; j <= n - word_length; j += word_length) {
            string word = s.substr(j, word_length);
            if (keys.find(word) == keys.end()) {
                start = j + word_length;
                appeared.clear();
            } else {
                ++appeared[word];
                while (keys[word] < appeared[word]) {
                    --appeared[s.substr(start, word_length)];
                    start += word_length;
                }
                if (j - start + word_length == m * word_length)
                    substrings.push_back(start);
            }
        }
    }
    return substrings;
}
