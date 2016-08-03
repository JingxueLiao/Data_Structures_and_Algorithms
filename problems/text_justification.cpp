// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
// Extra spaces between words should be distributed as evenly as possible.
// If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
// For the last line of text, it should be left justified and no extra space is inserted between words.

// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.
// Return the formatted lines as:
// [
//   "This    is    an",
//   "example  of text",
//   "justification.  "
// ]

// Note: Each word is guaranteed not to exceed L in length.

#include <vector>
#include <string>

using namespace std;

vector<string> FullJustify(const vector<string> &words, int maxWidth) {
    vector<string> text;
    int i = 0;
    while (i < words.size()) {
        int j = i;
        int left = maxWidth;
        while (j < words.size() && (int)words[j].size() <= left) {
            left = left - words[j].size() - 1;
            ++j;
        }
        string line(maxWidth, ' ');
        if (j == words.size() || i + 1 == j) {
            int k = 0;
            while (i < j) {
                line.replace(k, words[i].length(), words[i]);
                k = k + words[i].length() + 1;
                ++i;
            }
        } else if (j < words.size()) {
            int interval = j - i - 1 == 0 ? 1 : (left + 1) / (j - i - 1) + 1;
            int k = 0;
            for (int l = i; l < j; ++l) {
                line.replace(k, words[l].length(), words[l]);
                k = k + words[l].length() + interval;
                if (l - i < (left + 1) % (j - i - 1))
                    ++k;
            }
        }
        text.push_back(line);
        i = j;
    }   
    return text;
}       
