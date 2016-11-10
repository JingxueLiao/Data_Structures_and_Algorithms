// Write a function that takes a string as input and returns the string reversed.

// Example:
// Given s = "hello", return "olleh".

#include <string>
#include <algorithm>

using namespace std;

string ReverseString(const string &s) {
    string rs(s);
    int i = 0, j = s.size() - 1;
    while (i < j)
        swap(rs[i++], rs[j--]);
    return rs;
}
