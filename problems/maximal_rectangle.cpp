// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// For example, given the following matrix:
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Return 6.

#include <vector>
#include <algorithm>

using namespace std;


int MaximalRectangle(const vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
        return 0;
    int maximal = 0;
    vector<int> heights(matrix[0].size()), left(matrix[0].size()), right(matrix[0].size(), matrix[0].size());
    for (int i = 0; i < matrix.size(); ++i) {
        int cur_left = 0;
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == '0') {
                heights[j] = 0;
                cur_left = j + 1;
                left[j] = 0;
            } else {
                ++heights[j];
                left[j] = max(left[j], cur_left);
            }
        }
        int cur_right = matrix[0].size() - 1;
        for (int j = matrix[0].size() - 1; j >= 0; --j) {
            if (matrix[i][j] == '0') {
                cur_right = j - 1;
                right[j] = matrix[0].size();
            } else {
                right[j] = min(cur_right, right[j]);
            }
            if (maximal < (right[j] - left[j] + 1) * heights[j])
                maximal = (right[j] - left[j] + 1) * heights[j];
        }
    }
    return maximal;
}
