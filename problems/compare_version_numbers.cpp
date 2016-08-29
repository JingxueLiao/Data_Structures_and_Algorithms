// Compare two version numbers version1 and version2.
// If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

// Here is an example of version numbers ordering:
// 0.1 < 1.1 < 1.2 < 13.37

#include <string>

using namespace std;

int CompareVersion(const string &version1, const string &version2) {
    int i = 0, j = 0, n = version1.size(), m = version2.size();
    while (i < n && j < m) {
        int k = i, l = j;
        while (k < n && version1[k] != '.')
            ++k;
        while (l < m && version2[l] != '.')
            ++l;
        int a = stoi(version1.substr(i, k - i)), b = stoi(version2.substr(j, l - j));
        if (a < b)
            return -1;
        else if (b < a)
            return 1;
        i = k + 1;
        j = l + 1;
    }
    while (i < n) {
        int k = i;
        while (k < n && version1[k] != '.')
            ++k;
        if (stoi(version1.substr(i, k - i)))
            return 1;
        i = k + 1;
    }
    while (j < m) {
        int l = j;
        while (l < m && version2[l] != '.')
            ++l;
        if (stoi(version2.substr(j, l - j)))
            return -1;
        j = l + 1;
    }
    return 0;
}
