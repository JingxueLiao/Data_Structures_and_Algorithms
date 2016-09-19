// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
// Find the two elements that appear only once.

// For example:
// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

// Note:
// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

#include <vector>

using namespace std;

vector<int> SingleNumber(const vector<int> &nums) {
    int a = 0, b = 0;
    for (auto p = nums.begin(); p != nums.end(); ++p)
        a ^= *p;
    int i = 0;
    while ((a & 1 << i) == 0)
        ++i;
    for (auto p = nums.begin(); p != nums.end(); ++p) {
        if (*p & 1 << i)
            b ^= *p;
    }
    return vector<int>{ a ^ b, b };
}
