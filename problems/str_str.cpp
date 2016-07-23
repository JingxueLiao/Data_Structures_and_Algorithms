// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include <string>
#include <vector>

using namespace std;

vector<int> GenerateNext(const string &needle) {
    if (needle.empty())
        return vector<int>();
    vector<int> next(needle.size());
    next[0] = -1;
    for (int i = 1; i < needle.size(); ++i) {
        int j = next[i - 1];
        while (j != -1 && needle[j] != needle[i - 1])
            j = next[j];
        next[i] = j + 1;
    }
    for (int i = 1; i < needle.size(); ++i)
        if (needle[i] == needle[next[i]])
            next[i] = next[next[i]];
    return next;
}

int StrStr(const string &haystack, const string &needle) {
    if (needle.empty())
        return 0;
    vector<int> next = GenerateNext(needle);
    int i = 0, j = 0;
    while (i < haystack.size()) {
        if (haystack[i] == needle[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
            if (j == -1) {
                ++i;
                j = 0;
            }
        }
        if (j == needle.size())
            return i - needle.size();
    }
    return -1;
}
