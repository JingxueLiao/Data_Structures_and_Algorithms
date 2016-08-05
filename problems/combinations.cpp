// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <vector>

using namespace std;

void dfs(vector<vector<int>> &combinations, vector<int> &cur, int begin, int n, int k) {
    if (k == 0) {
        combinations.push_back(cur);
        return;
    }
    --k;
    for (int i = begin; i <= n - k; ++i) {
        cur.push_back(i);
        dfs(combinations, cur, i + 1, n, k);
        cur.pop_back();
    }
}

vector<vector<int>> Combine(int n, int k) {
    vector<vector<int>> combinations;
    vector<int> cur;
    dfs(combinations, cur, 1, n, k);
    return combinations;
}
