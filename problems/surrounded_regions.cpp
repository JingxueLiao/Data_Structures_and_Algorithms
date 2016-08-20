// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// For example,
// X X X X
// X O O X
// X X O X
// X O X X

// After running your function, the board should be:
// X X X X
// X X X X
// X X X X
// X O X X

#include <vector>
#include <queue>
#include <utility>

using namespace std;

void Expand(vector<vector<char>> &board, int row, int column) {
    queue<pair<int, int>> level;
    level.push(make_pair(row, column));
    while (!level.empty()) {
        row = level.front().first;
        column = level.front().second;
        level.pop();
        if (board[row][column] != 'O')
            continue;
        board[row][column] = 'U';
        if (row > 0 && board[row - 1][column] == 'O')
            level.push(make_pair(row - 1, column));
        if (column > 0 && board[row][column - 1] == 'O')
            level.push(make_pair(row, column - 1));
        if (row < board.size() - 1 && board[row + 1][column] == 'O')
            level.push(make_pair(row + 1, column));
        if (column < board[0].size() - 1 && board[row][column + 1] == 'O')
            level.push(make_pair(row, column + 1));
    }
}

void Solve(vector<vector<char>> &board) {
    if (board.empty() || board[0].empty())
        return;
    for (int i = 0; i < board[0].size(); ++i)
        Expand(board, 0, i);
    for (int i = 1; i < board.size(); ++i)
        Expand(board, i, board[0].size() - 1);
    for (int i = board[0].size() - 2; i >= 0; --i)
        Expand(board, board.size() - 1, i);
    for (int i = board.size() - 2; i > 0; --i)
        Expand(board, i, 0);
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'U')
                board[i][j] = 'O';
        }
    }
}
