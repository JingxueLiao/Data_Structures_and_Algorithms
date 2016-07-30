// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// For example,
// Given the following matrix:
// [
//   [ 1, 2, 3 ],
//   [ 4, 5, 6 ],
//   [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

#include <vector>

using namespace std;

vector<int> SpiralOrder(const vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
        return vector<int>();
    vector<int> result;
    int rb = 0, re = matrix.size() - 1, cb = 0, ce = matrix[0].size() - 1;
    while (rb <= re && cb <= ce) {
        for (int i = cb; i <= ce; ++i)
            result.push_back(matrix[rb][i]);
        ++rb;
        for (int i = rb; i <= re; ++i)
            result.push_back(matrix[i][ce]);
        --ce;
        if (rb <= re) {
            for (int i = ce; i >= cb; --i)
                result.push_back(matrix[re][i]);
            --re;
        }
        if (cb <= ce) {
            for (int i = re; i >= rb; --i)
                result.push_back(matrix[i][cb]);
            ++cb;
        }
    }
    return result;
}
