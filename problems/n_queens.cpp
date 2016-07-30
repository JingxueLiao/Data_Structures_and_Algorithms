// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

// For example,
// There exist two distinct solutions to the 4-queens puzzle:
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

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

void Solve(vector<vector<string>> &solutions, vector<string> &cur, int row) {
    if (row == cur.size()) {
        solutions.push_back(cur);
        return;
    }
    for (int i = 0; i < cur.size(); ++i) {
        if (Valid(cur, row, i)) {
            cur[row][i] = 'Q';
            Solve(solutions, cur, row + 1);
            cur[row][i] = '.';
        }
    }
}

vector<vector<string>> SolveNQueens(int n) {
    if (n <= 0)
        return vector<vector<string>>();
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    Solve(solutions, board, 0);
    return solutions;
}
