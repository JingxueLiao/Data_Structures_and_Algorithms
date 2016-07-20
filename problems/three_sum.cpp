// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note: The solution set must not contain duplicate triplets.

// For example, given array S = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ThreeSum(vector<int> nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int i = 0;
    while (i < nums.size()) {
        int target = -nums[i];
        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            if (nums[j] + nums[k] < target) {
                ++j;
            } else if (target < nums[j] + nums[k]) {
                --k;
            } else {
                result.push_back(vector<int>{ nums[i], nums[j], nums[k] });
                ++j;
                while (j < k && nums[j] == nums[j - 1])
                    ++j;
            }
        }
        ++i;
        while (i < nums.size() && nums[i] == nums[i - 1])
            ++i;
    }
    return result;
}
