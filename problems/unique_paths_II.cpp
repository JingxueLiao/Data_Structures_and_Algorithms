// Follow up for "Unique Paths":

// Now consider if some obstacles are added to the grids.
// How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.

#include <vector>

using namespace std;

int UniquePathsWithObstacles(const vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid.empty() || obstacleGrid[0].empty())
        return 0;
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    vector<int> paths(m);
    paths[0] = 1;
    for (int i = 0; i < n; ++i) {
        paths[0] = obstacleGrid[i][0] ? 0 : paths[0];
        for (int j = 1; j < m; ++j)
            paths[j] = obstacleGrid[i][j] ? 0 : paths[j - 1] + paths[j];
    }
    return paths[m - 1];
}
