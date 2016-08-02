// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

#include <vector>
#include <algorithm>

using namespace std;

int MinimumPathSum(const vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty())
        return 0;
    int n = grid.size(), m = grid[0].size();
    vector<int> sums(m);
    sums[0] = grid[0][0];
    for (int i = 1; i < m; ++i)
        sums[i] = sums[i - 1] + grid[0][i];
    for (int i = 1; i < n; ++i) {
        sums[0] += grid[i][0];
        for (int j = 1; j < m; ++j)
            sums[j] = min(sums[j - 1], sums[j]) + grid[i][j];
    }
    return sums[m - 1];
}
