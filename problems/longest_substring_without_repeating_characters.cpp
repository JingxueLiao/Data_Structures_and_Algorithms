/*
* Given a string, find the length of the longest substring without repeating characters.
* 
* Examples:
* Given "abcabcbb", the answer is "abc", which the length is 3.
* Given "bbbbb", the answer is "b", with the length of 1.
* Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <string>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> positions(128, -1);
    int start = 0;
    int longest = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (start <= positions[s[i]])
            start = positions[s[i]] + 1;
        else if (longest < i - start + 1)
            longest = i - start + 1;
        positions[s[i]] = i;
    }
    return longest;
}
