// Given an array of strings, group anagrams together.

// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
// Return:

// [
  // ["ate", "eat","tea"],
  // ["nat","tan"],
  // ["bat"]
// ]

// Note: All inputs will be in lower-case.

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>> GroupAnagrams(const vector<string> &strs) {
    vector<vector<string>> anagrams;
    unordered_map<string, int> groups;
    for (auto p = strs.begin(); p != strs.end(); ++p) {
        string s(*p);
        sort(s.begin(), s.end());
        if (groups.find(s) == groups.end()) {
            groups[s] = anagrams.size();
            anagrams.push_back(vector<string>());
        }
        anagrams[groups[s]].push_back(*p);
    }
    return anagrams;
}
