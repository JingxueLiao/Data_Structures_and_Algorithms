/*
* Implement atoi to convert a string to an integer.
*/

#include <string>
#include <climit>

using namespace std

int atoi(const string &str) {
    long long result = 0;
    int i = 0, n = str.size();
    while (i < n && str[i] == ' ')
        ++i;
    if (i < n) {
        bool negative = str[i] == '-';
        if (str[i] == '+' || str[i] == '-')
            ++i;
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + str[i] - '0';
            ++i;
            if (negative && -result < INT_MIN || !negative && result > INT_MAX)
                return negative ? INT_MIN : INT_MAX;
        }
        result = negative ? -result : result;
    }
    return result;
}
