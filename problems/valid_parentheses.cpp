// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <string>
#include <stack>

using namespace std;

bool IsValid(const string &s) {
    stack<char> unmatch;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            unmatch.push(s[i]);
        } else {
            if (unmatch.empty())
                return false;
            char pre = unmatch.top();
            unmatch.pop();
            if (s[i] == ')' && pre != '(' || s[i] == ']' && pre != '[' || s[i] == '}' && pre != '{')
                return false;
        }
    }
    return unmatch.empty();
}
