// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

// Example:
// Given "bcabc"
// Return "abc"

// Given "cbacdcbc"
// Return "acdb"

#include <string>
#include <vector>

using namespace std;

string RemoveDuplicateLetters(const string &s) {
    vector<int> characters(128);
    vector<bool> added(128);
    for (auto p = s.begin(); p != s.end(); ++p)
        ++characters[*p];
    string result;
    for (auto p = s.begin(); p != s.end(); ++p) {
        --characters[*p];
        if (!added[*p]) {
            while (!result.empty() && *p < result.back() && characters[result.back()]) {
                added[result.back()] = false;
                result.pop_back();
            }
            result.push_back(*p);
            added[*p] = true;
        }
    }
    return result;
}
