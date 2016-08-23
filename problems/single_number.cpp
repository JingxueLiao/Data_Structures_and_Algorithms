// Given an array of integers, every element appears twice except for one.
// Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity.
// Could you implement it without using extra memory?

#include <vector>

using namespace std;

int SingleNumber(const vector<int> &nums) {
    int single = 0;
    for (auto p = nums.begin(); p != nums.end(); ++p)
        single ^= *p;
    return single;
}
