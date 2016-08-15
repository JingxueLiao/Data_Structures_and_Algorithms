// Given numRows, generate the first numRows of Pascal's triangle.
 
// For example, given numRows = 5,
// Return
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

#include <vector>

using namespace std;

vector<vector<int>> Generate(int numRows) {
    if (numRows <= 0)
        return vector<vector<int>>();
    vector<vector<int>> triangle;
    for (int i = 1; i <= numRows; ++i) {
        triangle.push_back(vector<int>(i));
        triangle[i - 1][0] = triangle[i - 1][i - 1] = 1;
        for (int j = 1; j < i - 1; ++j)
            triangle[i - 1][j] = triangle[i - 2][j - 1] + triangle[i - 2][j];
    }
    return triangle;
}
