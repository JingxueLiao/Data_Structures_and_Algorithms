// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
// Each number in C may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

// For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
// A solution set is: 
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]

#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &combinations, vector<int> &cur, const vector<int> &candidates, int index, int target) {
    if (target == 0)
        combinations.push_back(cur);
    if (target <= 0 || index == candidates.size())
        return;
    int next = index;
    while (next != candidates.size() && candidates[next] == candidates[index])
        ++next;
    dfs(combinations, cur, candidates, next, target);
    for (int i = index; i != next; ++i) {
        target -= candidates[index];
        cur.push_back(candidates[index]);
        dfs(combinations, cur, candidates, next, target);
    }
    for (int i = index; i != next; ++i)
        cur.pop_back();
}

vector<vector<int>> CombinationSumII(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> combinations;
    vector<int> cur;
    dfs(combinations, cur, candidates, 0, target);
    return combinations;
}
