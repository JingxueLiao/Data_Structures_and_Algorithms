// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.

// Note: The solution set must not contain duplicate quadruplets.

// For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> FourSum(vector<int> nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int i = 0;
    while (i < nums.size()) {
        int j = i + 1;
        while (j < nums.size()) {
            int k = j + 1, l = nums.size() - 1;
            while (k < l) {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum < target) {
                    ++k;
                } else if (target < sum) {
                    --l;
                } else {
                    result.push_back(vector<int>{ nums[i], nums[j], nums[k], nums[l] });
                    ++k;
                    while (k < l && nums[k] == nums[k - 1])
                        ++k;
                }
            }
            ++j;
            while (j < nums.size() && nums[j] == nums[j - 1])
                ++j;
        }
        ++i;
        while (i < nums.size() && nums[i] == nums[i - 1])
            ++i;
    }
    return result;
}
