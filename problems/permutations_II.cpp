// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// For example,
// [1,1,2] have the following unique permutations:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<vector<int>> &permutations, vector<int> &nums, int cur) {
    if (cur == nums.size()) {
        permutations.push_back(nums);
        return;
    }
    unordered_set<int> added;
    for (int i = cur; i < nums.size(); ++i) {
        if (added.find(nums[i]) != added.end())
            continue;
        swap(nums[cur], nums[i]);
        dfs(permutations, nums, cur + 1);
        swap(nums[cur], nums[i]);
        added.insert(nums[i]);
    }
}

vector<vector<int>> PermuteUnique(vector<int> &nums) {
    vector<vector<int>> permutations;
    dfs(permutations, nums, 0);
    return permutations;
}
