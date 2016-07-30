// You are given an n x n 2D matrix representing an image.
// Rotate the image by 90 degrees (clockwise).

// Follow up:
// Could you do this in-place?

#include <vector>
#include <algorithm>

using namespace std;

void Rotate(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
        return;
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n / 2; ++i)
        swap(matrix[i], matrix[n - 1 - i]);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < m; ++j)
            swap(matrix[i][j], matrix[j][i]);
}
