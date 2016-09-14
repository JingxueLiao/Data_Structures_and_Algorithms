// Implement a basic calculator to evaluate a simple expression string.
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
// You may assume that the given expression is always valid.

// Some examples:
// "1 + 1" = 2
// " 2-1 + 2 " = 3
// "(1+(4+5+2)-3)+(6+8)" = 23
// Note: Do not use the eval built-in library function.

#include <string>
#include <stack>

using namespace std;

int Calculate(const string &s) {
    int result = 0, sign = 1;
    stack<int> operands;
    for (int i = 0; i < s.size();) {
        if (s[i] >= '0' && s[i] <= '9') {
            int tmp = 0;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                tmp = tmp * 10 + s[i] - '0';
                ++i;
            }
            result += sign * tmp;
        } else {
            if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                operands.push(result);
                operands.push(sign);
                result = 0;
                sign = 1;
            } else if (s[i] == ')') {
                sign = operands.top();
                operands.pop();
                result = operands.top() + sign * result;
                operands.pop();
            }
            ++i;
        }
    }
    return result;
}
