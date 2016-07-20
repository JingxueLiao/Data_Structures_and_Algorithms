// Write a function to find the longest common prefix string amongst an array of strings.

#include <string>
#include <vector>

using namespace std;

string LongestCommonPrefix(const vector<string> &strs) {
    if (strs.empty())
        return string();
    string prefix;
    int i = 0;
    while (true) {
        int j = 0;
        while (j < strs.size()) {
            if (i == strs[j].size() || strs[j][i] != strs[0][i])
                break;
            ++j;
        }
        if (j != strs.size())
            break;
        prefix.push_back(strs[0][i]);
        ++i;
    }
    return prefix;
}
