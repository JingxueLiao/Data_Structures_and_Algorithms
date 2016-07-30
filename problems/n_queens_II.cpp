// Follow up for N-Queens problem.
// Now, instead outputting board configurations, return the total number of distinct solutions.


#include <string>
#include <vector>

using namespace std;

bool Valid(const vector<string> &board, int row, int column) {
    int n = board.size();
    for (int i = 0; i < row; ++i)
        if (board[i][column] == 'Q')
            return false;
    for (int i = 1; i <= row; ++i) {
        if (column - i >= 0 && board[row - i][column - i] == 'Q')
            return false;
        if (column + i < n && board[row - i][column + i] == 'Q')
            return false;
    }
    return true;
}

int Solve(vector<string> &cur, int row) {
    if (row == cur.size()) {
        return 1;
    }
    int total = 0;
    for (int i = 0; i < cur.size(); ++i) {
        if (Valid(cur, row, i)) {
            cur[row][i] = 'Q';
            total += Solve(cur, row + 1);
            cur[row][i] = '.';
        }
    }
    return total;
}

int SolveNQueens(int n) {
    if (n <= 0)
        return 0;
    vector<string> board(n, string(n, '.'));
    return Solve(board, 0);
}
