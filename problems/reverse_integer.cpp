/*
* Reverse digits of an integer.
* 
* Example1: x = 123, return 321
* Example2: x = -123, return -321
*/

#include <climit>

int reverse(int x) {
    long long origin = x, result = 0;
    bool negative = origin < 0;
    origin = negative ? -origin : origin;
    while (origin) {
        result = result * 10 + origin % 10;
        origin /= 10;
    }
    result = negative ? -result : result;
    if (result > INT_MAX || result < INT_MIN)
        result = 0;
    return result;
}
