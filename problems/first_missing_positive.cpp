// Given an unsorted integer array, find the first missing positive integer.
// 
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.
// 
// Your algorithm should run in O(n) time and uses constant space.

#include <vector>
#include <algorithm>

using namespace std;

int FirstMissingPositive(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        while (nums[i] != i + 1 && nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return nums.size() + 1;
}
