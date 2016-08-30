// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
// When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

// For example,
// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
// Return:
// ["AAAAACCCCC", "CCCCCAAAAA"].

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> FindRepeatedDnaSequences(const string &s) {
    if (s.size() < 10)
        return vector<string>();
    vector<string> sequences;
    unordered_map<int, int> appeared;
    unsigned int cur = 0;
    for (int i = 0; i < 9; ++i)
        cur = cur << 3 | s[i] & 0x7;
    for (int i = 9; i < s.size(); ++i) {
        cur = cur << 3 & 0x3fffffff | s[i] & 0x7;
        if (appeared[cur]++ == 1)
            sequences.push_back(s.substr(i - 9, 10));
    }
    return sequences;
}
