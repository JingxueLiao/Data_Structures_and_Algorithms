// Given an array of integers, every element appears three times except for one.
// Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity.
// Could you implement it without using extra memory?

#include <vector>

using namespace std;

int SingleNumber(const vector<int> &nums) {
    int one = 0, two = 0;
    for (auto p = nums.begin(); p != nums.end(); ++p) {
        one = (one ^ *p) & ~two;
        two = (two ^ *p) & ~one;
    }
    return one;
}
