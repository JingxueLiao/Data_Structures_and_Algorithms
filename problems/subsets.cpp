// Given a set of distinct integers, nums, return all possible subsets.

// Note: The solution set must not contain duplicate subsets.

// For example,
// If nums = [1,2,3], a solution is:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#include <vector>

using namespace std;

void dfs(vector<vector<int>> &result, vector<int> &cur, const vector<int> &nums, int begin) {
    if (begin == nums.size()) {
        result.push_back(cur);
        return;
    }
    dfs(result, cur, nums, begin + 1);
    cur.push_back(nums[begin]);
    dfs(result, cur, nums, begin + 1);
    cur.pop_back();
}

vector<vector<int>> Subsets(const vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> cur;
    dfs(result, cur, nums, 0);
    return result;
}
