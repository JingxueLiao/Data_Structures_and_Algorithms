// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.

// For example, given array S = {-1 2 1 -4}, and target = 1.
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int ThreeSumClosest(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());
    int i = 0;
    int closest = nums[0] + nums[1] + nums[2];
    while (i < nums.size()) {
        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            if (fabs(target - nums[i] - nums[j] - nums[k]) < fabs(target - closest))
                closest = nums[i] + nums[j] + nums[k];
            if (nums[i] + nums[j] + nums[k] < target)
                ++j;
            else if (target < nums[i] + nums[j] + nums[k])
                --k;
            else
                return target;
        }
        ++i;
        while (i < nums.size() && nums[i] == nums[i - 1])
            ++i;
    }
    return closest;
}
