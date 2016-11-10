// Write a function that takes a string as input and reverse only the vowels of a string.

// Example 1:
// Given s = "hello", return "holle".

// Example 2:
// Given s = "leetcode", return "leotcede".

// Note:
// The vowels does not include the letter "y".

#include <string>

using namespace std;

bool IsVowel(char c) {
    static string vowels("aeiouAEIOU");
    for (auto p = vowels.begin(); p != vowels.end(); ++p)
        if (*p == c)
            return true;
    return false;
}

string ReverseVowels(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        while (i < j && !IsVowel(s[i]))
            ++i;
        while (i < j && !IsVowel(s[j]))
            --j;
        if (i < j)
            swap(s[i++], s[j--]);
    }
    return s;
}
