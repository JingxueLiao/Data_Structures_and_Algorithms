// Given a 2D board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once.

// For example,
// Given board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

#include <vector>
#include <string>

using namespace std;

bool dfs(const vector<vector<char>> &board, string &word, int begin, int row, int column, vector<vector<bool>> &visited) {
    if (begin == word.size())
        return true;
    if (row < 0 || row == board.size() || column < 0 || column == board[0].size() || visited[row][column] || board[row][column] != word[begin])
        return false;
    visited[row][column] = true;
    bool found = false;
    if (dfs(board, word, begin + 1, row - 1, column, visited) || dfs(board, word, begin + 1, row, column + 1, visited) || dfs(board, word, begin + 1, row + 1, column, visited) || dfs(board, word, begin + 1, row, column - 1, visited))
        found = true;
    visited[row][column] = false;
    return found;
}

bool Exist(const vector<vector<char>> &board, string &word) {
    if (board.empty() || board[0].empty() || word.empty())
        return false;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (dfs(board, word, 0, i, j, visited))
                return true;
        }
    }
    return false;
}
