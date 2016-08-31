// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:
// 11110
// 11010
// 11000
// 00000
// Answer: 1

// Example 2:
// 11000
// 11000
// 00100
// 00011
// Answer: 3

#include <vector>
#include <queue>
#include <utility>

using namespace std;

void Extend(const vector<vector<char>> &grid, vector<vector<bool>> &visited, int row, int column) {
    queue<pair<int, int>> candidates;
    candidates.push(make_pair(row, column));
    visited[row][column] = true;
    while (!candidates.empty()) {
        int r = candidates.front().first, c = candidates.front().second;
        candidates.pop();
        if (r > 0 && grid[r - 1][c] == '1' && !visited[r - 1][c]) {
            candidates.push(make_pair(r - 1, c));
            visited[r - 1][c] = true;
        }
        if (r < grid.size() - 1 && grid[r + 1][c] == '1' && !visited[r + 1][c]) {
            candidates.push(make_pair(r + 1, c));
            visited[r + 1][c] = true;
        }
        if (c > 0 && grid[r][c - 1] == '1' && !visited[r][c - 1]) {
            candidates.push(make_pair(r, c - 1));
            visited[r][c - 1] = true;
        }
        if (c < grid[0].size() - 1 && grid[r][c + 1] == '1' && !visited[r][c + 1]) {
            candidates.push(make_pair(r, c + 1));
            visited[r][c + 1] = true;
        }
    }
}

int NumIslands(const vector<vector<char>> &grid) {
    if (grid.empty() || grid[0].empty())
        return 0;
    int num = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                ++num;
                Extend(grid, visited, i, j);
            }
        }
    }
    return num;
}
