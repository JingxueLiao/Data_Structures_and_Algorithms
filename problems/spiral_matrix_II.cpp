// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// For example,
// Given n = 3,
// You should return the following matrix:
// [
//   [ 1, 2, 3 ],
//   [ 8, 9, 4 ],
//   [ 7, 6, 5 ]
// ]

#include <vector>

using namespace std;

vector<vector<int>> GenerateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    int cur = 1;
    for (int i = 0; i < n / 2; ++i) {
        int b = i, e = n - 1 - i;
        for (int j = i; j < n - 1 - i; ++j)
            matrix[i][j] = cur++;
        for (int j = i; j < n - 1 - i; ++j)
            matrix[j][n - 1 - i] = cur++;
        for (int j = n - 1 - i; j > i; --j)
            matrix[n - 1 - i][j] = cur++;
        for (int j = n - 1 - i; j > i; --j)
            matrix[j][i] = cur++;
    }
    if (n % 2)
        matrix[n / 2][n / 2] = cur;
    return matrix;
}
