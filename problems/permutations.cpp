// Given a collection of distinct numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &permutations, vector<int> &nums, int cur) {
    if (cur == nums.size()) {
        permutations.push_back(nums);
        return;
    }
    for (int i = cur; i < nums.size(); ++i) {
        swap(nums[cur], nums[i]);
        dfs(permutations, nums, cur + 1);
        swap(nums[cur], nums[i]);
    }
}

vector<vector<int>> Permute(vector<int> &nums) {
    vector<vector<int>> permutations;
    dfs(permutations, nums, 0);
    return permutations;
}
