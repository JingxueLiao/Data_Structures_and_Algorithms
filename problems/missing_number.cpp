// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

// For example,
// Given nums = [0, 1, 3] return 2.

// Note:
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

#include <vector>

using namespace std;

int MissingNumber(const vector<int> &nums) {
    if (nums.empty())
        return 0;
    int n = nums.size();
    int sum = 0;
    for (auto p = nums.begin(); p != nums.end(); ++p)
        sum += *p;
    return n * (1 + n) / 2 - sum;
}
