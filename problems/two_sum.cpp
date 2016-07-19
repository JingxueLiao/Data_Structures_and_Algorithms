// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> TwoSum(const vector<int> &nums, int target) {
    vector<int> result(2);
    unordered_map<int, int> appeared;
    for (int i = 0; i < nums.size(); ++i) {
        auto p = appeared.find(target - nums[i]);
        if (p != appeared.end()) {
            result[0] = p->second;
            result[1] = i;
            break;
        }
        appeared[nums[i]] = i;
    }
    return result;
}

/*
vector<int> TwoSum(const vector<int> &nums, int target) {
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    int begin = 0, end = sorted.size() - 1;
    vector<int> result(2);
    while (begin < end) {
        if (sorted[begin] + sorted[end] < target) {
            ++begin;
        } else if (target < sorted[begin] + sorted[end]) {
            --end;
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == sorted[begin] || nums[i] == sorted[end]) {
                    result[0] = i;
                    break;
                }
            }
            for (int i = nums.size() - 1; i >= 0; --i) {
                if (nums[i] == sorted[begin] || nums[i] == sorted[end]) {
                    result[1] = i;
                    break;
                }
            }
            break;
        }
    }
    return result;
}
*/
