// Given a m x n matrix, if an element is 0, set its entire row and column to 0.
// Do it in place.

#include <vector>

using namespace std;

void SetZeroes(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
        return;
    bool first_row = false;
    for (auto p = matrix[0].begin(); p != matrix[0].end(); ++p) {
        if (*p == 0) {
            first_row = true;
            break;
        }
    }
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < matrix.size(); ++i) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < matrix[0].size(); ++j)
                matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < matrix[0].size(); ++i) {
        if (matrix[0][i] == 0) {
            for (int j = 1; j < matrix.size(); ++j)
                matrix[j][i] = 0;
        }
    }
    if (first_row) {
        for (int i = 0; i < matrix[0].size(); ++i)
            matrix[0][i] = 0;
    }
}
