// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

// For example, given candidate set [2, 3, 6, 7] and target 7, 
// A solution set is: 
// [
//   [7],
//   [2, 2, 3]
// ]

#include <vector>

using namespace std;

void dfs(vector<vector<int>> &combinations, vector<int> &cur, const vector<int> &candidates, int index, int target) {
    if (target == 0) {
        combinations.push_back(cur);
        return;
    }
    if (index == candidates.size())
        return;
    int i = 0;
    while (target >= 0) {
        dfs(combinations, cur, candidates, index + 1, target);
        cur.push_back(candidates[index]);
        target -= candidates[index];
        ++i;
    }
    while (i--)
        cur.pop_back();
}

vector<vector<int>> CombinationSum(const vector<int> &candidates, int target) {
    vector<vector<int>> combinations;
    vector<int> cur;
    dfs(combinations, cur, candidates, 0, target);
    return combinations;
}
