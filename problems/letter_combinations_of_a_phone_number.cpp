// Given a digit string, return all possible letter combinations that the number could represent.
// Input: Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

#include <string>
#include <vector>

using namespace std;

void dfs(vector<string> &combinations, string &cur, const string &digits, int index) {
    static vector<string> mapping{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    if (index == digits.size()) {
        combinations.push_back(cur);
        return;
    }
    for (auto p = mapping[digits[index] - '0'].begin(); p != mapping[digits[index] - '0'].end(); ++p) {
        cur.push_back(*p);
        dfs(combinations, cur, digits, index + 1);
        cur.pop_back();
    }
}

vector<string> LetterCombinations(const string &digits) {
    if (digits.empty())
        return vector<string>();
    vector<string> combinations;
    string cur;
    dfs(combinations, cur, digits, 0);
    return combinations;
}
