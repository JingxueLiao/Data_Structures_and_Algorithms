// Additive number is a string whose digits can form additive sequence.

// A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

// For example:
// "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

// 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
// "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
// 1 + 99 = 100, 99 + 100 = 199

// Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

// Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

// Follow up:
// How would you handle overflow for very large input integers?

#include <string>
#include <algorithm>

using namespace std;

string sum(const string &a, const string &b) {
    if (a.empty() && b.empty())
        return string();
    int n1 = a.size(), n2 = b.size();
    string result(max(n1, n2) + 1, '0');
    int n3 = result.size();
    bool carry = false;
    for (int i = 1; i <= result.size(); ++i) {
        int num1 = i <= n1 ? a[n1 - i] - '0' : 0;
        int num2 = i <= n2 ? b[n2 - i] - '0' : 0;
        result[n3 - i] = '0' + (num1 + num2 + carry) % 10;
        carry = num1 + num2 + carry >= 10;
    }
    if (result[0] == '0')
        result = result.substr(1);
    return result;
}

bool IsAdditiveNumber(const string &num) {
    for (int i = 1; i < num.size() - 1; ++i) {
        for (int j = 1; i + j < num.size(); ++j) {
            string a = num.substr(0, i);
            string b = num.substr(i, j);
            int k = i + j;
            while (k < num.size()) {
                string c = sum(a, b);
                if (c.size() <= num.size() - k && c == num.substr(k, c.size())) {
                    k += c.size();
                    a = move(b);
                    b = move(c);
                } else {
                    break;
                }
            }
            if (k == num.size())
                return true;
            if (num[i] == '0')
                break;
        }
        if (num[0] == '0')
            break;
    }
    return false;
}
