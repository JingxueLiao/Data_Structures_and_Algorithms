// Given two numbers represented as strings, return multiplication of the numbers as a string.
// 
// Note:
// The numbers can be arbitrarily large and are non-negative.
// Converting the input string to integer is NOT allowed.
// You should NOT use internal library such as BigInteger.

#include <string>

using namespace std;

string Multiply(const string &num1, const string &num2) {
    if (num1.empty() || num2.empty())
        return string();
    int n = num1.size(), m = num2.size();
    string result(n + m, '0');
    for (int i = m - 1; i >= 0; --i) {
        int b = num2[i] - '0';
        int carry = 0;
        for (int j = n - 1; j >= 0; --j) {
            int a = num1[j] - '0';
            int cur = a * b + carry + result[i + j + 1] - '0';
            result[i + j + 1] = '0' + cur % 10;
            carry = cur / 10;
        }
        int j = i;
        while (carry) {
            int cur = result[j] - '0' + carry;
            result[j] = '0' + cur % 10;
            carry = cur / 10;
            --j;
        }
    }
    int i = 0;
    while (i < result.size() - 1 && result[i] == '0')
        ++i;
    return result.substr(i, result.size() - i);
}
