// Divide two integers without using multiplication, division and mod operator.
// If it is overflow, return MAX_INT.

#include <climits>
#include <cmath>

int Divide(int dividend, int divisor) {
    if (divisor == 0)
        return INT_MAX;
    bool negative = dividend < 0 ^ divisor < 0;
    long long a = dividend, b = divisor;
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    long long result = 0;
    while (b <= a) {
        long long i = 1, j = b;
        while (j << 1 <= a) {
            i <<= 1;
            j <<= 1;
        }
        result += i;
        a -= j;
    }
    result = negative ? -result : result;
    if (result > INT_MAX || result < INT_MIN)
        result = INT_MAX;
    return result;
}
