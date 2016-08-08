// Given a collection of integers that might contain duplicates, nums, return all possible subsets.

// Note: The solution set must not contain duplicate subsets.

// For example,
// If nums = [1,2,2], a solution is:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &subsets, vector<int> &cur, vector<int> &nums, int begin) {
    if (begin == nums.size()) {
        subsets.push_back(cur);
        return;
    }
    int i = begin;
    while (i < nums.size() && nums[i] == nums[begin]) {
        ++i;
        cur.push_back(nums[begin]);
    }
    dfs(subsets, cur, nums, i);
    while (begin != i) {
        ++begin;
        cur.pop_back();
        dfs(subsets, cur, nums, i);
    }
}

vector<vector<int>> SubsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> subsets;
    vector<int> cur;
    dfs(subsets, cur, nums, 0);
    return subsets;
}
