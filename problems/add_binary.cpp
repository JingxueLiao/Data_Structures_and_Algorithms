// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".

#include <string>
#include <algorithm>

using namespace std;

string AddBinary(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    string sum(max(n, m) + 1, '0');
    int carry = false;
    for (int i = 1; i <= sum.size(); ++i) {
        int num1 = i <= n ? a[n - i] - '0' : 0, num2 = i <= m ? b[m - i] - '0' : 0;
        sum[sum.size() - i] += (num1 + num2 + carry) % 2;
        carry = (num1 + num2 + carry) / 2;
    }
    return sum[0] == '0' ? sum.substr(1) : sum;
}
