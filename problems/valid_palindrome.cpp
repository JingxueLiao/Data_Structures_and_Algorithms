// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 
// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

#include <string>

using namespace std;

bool IsAlpha(char c) {
    return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}

bool IsNumber(char c) {
    return c >= '0' && c <= '9';
}

bool IsPalindrome(const string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        while (i < j && !IsAlpha(s[i]) && !IsNumber(s[i]))
            ++i;
        while (i < j && !IsAlpha(s[j]) && !IsNumber(s[j]))
            --j;
        if (i < j && !(IsNumber(s[i]) && IsNumber(s[j]) && s[i] == s[j] || IsAlpha(s[i]) && IsAlpha(s[j]) && (s[i] == s[j] || s[i] - s[j] == 'A' - 'a' || s[i] - s[j] == 'a' - 'A')))
            return false;
        ++i;
        --j;
    }
    return true;
}
