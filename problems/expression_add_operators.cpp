// Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

// Examples: 
// "123", 6 -> ["1+2+3", "1*2*3"] 
// "232", 8 -> ["2*3+2", "2+3*2"]
// "105", 5 -> ["1*0+5","10-5"]
// "00", 0 -> ["0+0", "0-0", "0*0"]
// "3456237490", 9191 -> []

#include <string>
#include <vector>

using namespace std;

void dfs(const string &num, int pos, int target, long long pre, int factor, vector<string> &expressions, string expression) {
    if (pos == num.size()) {
        if (pre == target) {
            expressions.push_back(expression);
        }
        return;
    }
    long long cur = 0;
    for (int i = pos; i < num.size() - 1; ++i) {
        cur = cur * 10 + num[i] - '0';
        dfs(num, i + 1, target, pre + cur * factor, 1, expressions, expression + num.substr(pos, i - pos + 1) + "+");
        dfs(num, i + 1, target, pre + cur * factor, -1, expressions, expression + num.substr(pos, i - pos + 1) + "-");
        dfs(num, i + 1, target, pre, factor * cur, expressions, expression + num.substr(pos, i - pos + 1) + "*");
        if (num[pos] == '0')
            return;
    }
    cur = cur * 10 + num.back() - '0';
    dfs(num, num.size(), target, pre + cur * factor, 1, expressions, expression + num.substr(pos));
}

vector<string> AddOperators(const string &num, int target) {
    vector<string> expressions;
    string expression;
    dfs(num, 0, target, 0, 1, expressions, expression);
    return expressions;
}
