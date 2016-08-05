// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,

// Consider the following matrix:

// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

#include <vector>

using namespace std;

bool SearchMatrix(const vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
        return false;
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int i = mid / m, j = mid % m;
        if (matrix[i][j] < target)
            low = mid + 1;
        else if (target < matrix[i][j])
            high = mid - 1;
        else
            return true;
    }
    return false;
}
