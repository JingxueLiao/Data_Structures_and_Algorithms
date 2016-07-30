// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.

// For example:
// A = [2,3,1,1,4], return true.
// A = [3,2,1,0,4], return false.

#include <vector>

using namespace std;

bool CanJump(const vector<int> &nums) {
    int longest = 0;
    int i = 0;
    while (longest < nums.size() - 1 && i <= longest) {
        if (longest < i + nums[i])
            longest = i + nums[i];
        ++i;
    }
    return longest >= nums.size() - 1;
}
