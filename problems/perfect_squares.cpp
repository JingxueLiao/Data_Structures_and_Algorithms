// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int NumSquares(int n) {
    if (n <= 0)
        return 0;
    vector<int> squares(n + 1, INT_MAX);
    squares[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            squares[i] = min(squares[i], squares[i - j * j] + 1);
        }
    }
    return squares[n];
}
