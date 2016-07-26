// Determine if a Sudoku is valid.
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable.
// Only the filled cells need to be validated.

#include <vector>

using namespace std;

bool IsValidSudoku(const vector<vector<char>> &board) {
    vector<bool> appear(9);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            appear[j] = false;
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.')
                continue;
            if (appear[board[i][j] - '1'])
                return false;
            appear[board[i][j] - '1'] = true;
        }
        for (int j = 0; j < 9; ++j)
            appear[j] = false;
        for (int j = 0; j < 9; ++j) {
            if (board[j][i] == '.')
                continue;
            if (appear[board[j][i] - '1'])
                return false;
            appear[board[j][i] - '1'] = true;
        }
        for (int j = 0; j < 9; ++j)
            appear[j] = false;
        for (int j = 0; j < 9; ++j) {
            int r = i / 3 * 3 + j / 3, c = i % 3 * 3 + j % 3;
            if (board[r][c] == '.')
                continue;
            if (appear[board[r][c] - '1'])
                return false;
            appear[board[r][c] - '1'] = true;
        }
    }
    return true;
}
