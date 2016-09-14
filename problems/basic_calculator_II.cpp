// Implement a basic calculator to evaluate a simple expression string.
// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
// You may assume that the given expression is always valid.

// Some examples:
// "3+2*2" = 7
// " 3/2 " = 1
// " 3+5 / 2 " = 5

#include <string>
#include <stack>

using namespace std;

int Calculate(const string &s) {
    int result = 0, cur = 0, pre = 0, sign = 1;
    char ope = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            continue;
        } else if (s[i] >= '0' && s[i] <= '9') {
            cur = cur * 10 + s[i] - '0';
        } else {
            if (ope == '*')
                cur = pre * cur;
            else if (ope == '/')
                cur = pre / cur;
            if (s[i] == '+' || s[i] == '-') {
                result += sign * cur;
                sign = s[i] == '+' ? 1 : -1;
            }
            ope = s[i];
            pre = cur;
            cur = 0;
        }
    }
    if (ope == '*')
        cur = pre * cur;
    else if (ope == '/')
        cur = pre / cur;
    result += sign * cur;
    return result;
}
