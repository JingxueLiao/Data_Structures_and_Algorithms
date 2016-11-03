// Given an integer matrix, find the length of the longest increasing path.

// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

// Example 1:

// nums = [
  // [9,9,4],
  // [6,6,8],
  // [2,1,1]
// ]
// Return 4
// The longest increasing path is [1, 2, 6, 9].

// Example 2:

// nums = [
  // [3,4,5],
  // [3,2,6],
  // [2,2,1]
// ]
// Return 4
// The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

#include <vector>
#include <algorithm>

using namespace std;

int LongestPathLength(const vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &paths) {
    if (paths[x][y] == 0) {
        int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size() && matrix[x][y] < matrix[nx][ny])
                paths[x][y] = max(paths[x][y], LongestPathLength(matrix, nx, ny, paths));
        }
        ++paths[x][y];
    }
    return paths[x][y];
}

int LongestIncreasingPath(const vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
        return 0;
    vector<vector<int>> paths(matrix.size(), vector<int>(matrix[0].size()));
    int longestPath = 0;
    for (int i = 0; i < matrix.size(); ++i)
        for (int j = 0; j < matrix[0].size(); ++j)
            longestPath = max(longestPath, LongestPathLength(matrix, i, j, paths));
    return longestPath;
}
