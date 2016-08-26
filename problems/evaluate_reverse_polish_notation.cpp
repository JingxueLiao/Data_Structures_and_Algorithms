// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 
// Valid operators are +, -, *, /.
// Each operand may be an integer or another expression.
 
// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

#include <string>
#include <vector>
#include <stack>

using namespace std;

int EvalRPN(const vector<string> &tokens) {
    stack<int> operands;
    for (auto p = tokens.begin(); p != tokens.end(); ++p) {
        if (*p == "+" || *p == "-" || *p == "*" || *p == "/") {
            int a, b;
            b = operands.top();
            operands.pop();
            a = operands.top();
            operands.pop();
            switch ((*p)[0]) {
                case '+' : a += b; break;
                case '-' : a -= b; break;
                case '*' : a *= b; break;
                case '/' : a /= b; break;
            }
            operands.push(a);
        } else {
            operands.push(stoi(*p));
        }
    }
    return operands.top();
}
