// Given a non-negative number represented as an array of digits, plus one to the number.
// The digits are stored such that the most significant digit is at the head of the list.

#include <vector>

using namespace std;

vector<int> PlusOne(vector<int> &digits) {
    bool carry = true;
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] == 9) {
            digits[i] = 0;
        } else {
            ++digits[i];
            carry = false;
            break;
        }
    }
    if (carry) {
        digits.push_back(0);
        digits[0] = 1;
    }
    return digits;
}
