// Write a program to find the n-th ugly number.
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// Note that 1 is typically treated as an ugly number.

#include <vector>
#include <algorithm>

using namespace std;

int NthUglyNumber(int n) {
    if (n <= 0)
        return 0;
    vector<int> ugly_numbers(n);
    ugly_numbers[0] = 1;
    int two = 0, three = 0, five = 0;
    for (int i = 1; i < n; ++i) {
        ugly_numbers[i] = min(2 * ugly_numbers[two], min(3 * ugly_numbers[three], 5 * ugly_numbers[five]));
        if (2 * ugly_numbers[two] == ugly_numbers[i])
            ++two;
        if (3 * ugly_numbers[three] == ugly_numbers[i])
            ++three;
        if (5 * ugly_numbers[five] == ugly_numbers[i])
            ++five;
    }
    return ugly_numbers[n - 1];
}
