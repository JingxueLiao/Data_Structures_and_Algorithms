// Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

// Example 1:
// Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
// Return 16
// The two words can be "abcw", "xtfn".

// Example 2:
// Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
// Return 4
// The two words can be "ab", "cd".

// Example 3:
// Given ["a", "aa", "aaa", "aaaa"]
// Return 0
// No such pair of words.

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int MaxProduct(const vector<string> &words) {
    vector<int> appeared(words.size());
    for (int i = 0; i < words.size(); ++i) {
        for (auto p = words[i].begin(); p != words[i].end(); ++p) {
            appeared[i] |= 1 << *p - 'a';
        }
    }
    int maximum = 0;
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words.size(); ++j) {
            if ((appeared[i] & appeared[j]) == 0 && maximum < words[i].size() * words[j].size()) {
                maximum = words[i].size() * words[j].size();
            }
        }
    }
    return maximum;
}
