// Write a program to solve a Sudoku puzzle by filling the empty cells.
// Empty cells are indicated by the character '.'.
// You may assume that there will be only one unique solution.

#include <vector>

using namespace std;

bool Valid(const vector<vector<char>> &board, int row, int column, char c) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == c && i != column)
            return false;
        if (board[i][column] == c && i != row)
            return false;
        int j = row / 3 * 3 + i / 3, k = column / 3 * 3 + i % 3;
        if (board[j][k] == c && j != row && k != column)
            return false;
    }
    return true;
}

bool Solve(vector<vector<char>> &board, int row, int column) {
    for (; row < 9; ++row) {
        for (; column < 9; ++column) {
            if (board[row][column] != '.')
                continue;
            for (char c = '1'; c <= '9'; ++c) {
                board[row][column] = c;
                if (Valid(board, row, column, c) && Solve(board, row, column + 1))
                    return true;
            }
            board[row][column] = '.';
            return false;
        }
        column = 0;
    }
    return true;
}

void SolveSudoku(vector<vector<char>> &board) {
    Solve(board, 0, 0);
}
