// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// For example, given the following matrix:
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Return 4.

#include <vector>
#include <algorithm>

using namespace std;

int MaximalSquare(const vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
        return 0;
    vector<int> areas(matrix[0].size() + 1);
    int maximal = 0;
    for (unsigned int i = 0; i < matrix.size(); ++i) {
        int pre = 0;
        for (unsigned int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == '0') {
                areas[j + 1] = 0;
            } else {
                int tmp = areas[j + 1];
                areas[j + 1] = min(pre, min(areas[j], areas[j + 1])) + 1;
                pre = tmp;
                if (maximal < areas[j + 1])
                    maximal = areas[j + 1];
            }
        }
    }
    return maximal * maximal;
}
