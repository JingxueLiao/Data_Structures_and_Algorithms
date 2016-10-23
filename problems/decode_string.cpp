// Given an encoded string, return it's decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

// Examples:

// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

#include <string>

using namespace std;

string DecodeString(const string &s) {
    string decode;
    for (int i = 0; i < s.size(); ) {
        if (s[i] < '0' || s[i] > '9') {
            decode.push_back(s[i]);
            ++i;
        } else {
            int k = 0;
            int j = i;
            while (j < s.size() && s[j] >= '0' && s[j] <= '9') {
                k = k * 10 + s[j] - '0';
                ++j;
            }
            i = j + 1;
            int bracket = 0;
            do {
                if (s[j] == '[')
                    ++bracket;
                else if (s[j] == ']')
                    --bracket;
                ++j;
            } while (j < s.size() && bracket != 0);
            string t = DecodeString(s.substr(i, j - i - 1));
            while (k--)
                decode += t;
            i = j;
        }
    }
    return decode;
}
