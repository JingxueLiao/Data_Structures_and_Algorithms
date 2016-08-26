// Given an input string, reverse the string word by word.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

// Try to solve it in-place in O(1) space.

#include <string>
#include <algorithm>

using namespace std;

void ReverseWords(string &s) {
    if (s.empty())
        return;
    int i = 0, j = 0;
    while (j < s.size() && s[j] == ' ')
        ++j;
    while (j < s.size()) {
        while (j < s.size() && s[j] != ' ')
            s[i++] = s[j++];
        s[i++] = ' ';
        while (j < s.size() && s[j] == ' ')
            ++j;
    }
    i = i == 0 ? 0 : i - 1;
    reverse(s.begin(), s.begin() + i);
    j = 0;
    while (j < i) {
        int k = j;
        while (k < i && s[k] != ' ')
            ++k;
        reverse(s.begin() + j, s.begin() + k);
        j = k + 1;
    }
    s.resize(i);
}
