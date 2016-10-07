// The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.

// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population..
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// Write a function to compute the next state (after one update) of the board given its current state.

// Follow up: 
// Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
// In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

#include <vector>

using namespace std;

void GameOfLife(vector<vector<int>> &board) {
    if (board.empty() || board[0].empty())
        return;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            int neighbors = 0;
            for (int k = i - 1; k <= i + 1; ++k) {
                for (int l = j - 1; l <= j + 1; ++l) {
                    if (k >= 0 && k < board.size() && l >= 0 && l < board[0].size() && !(k == i && l == j) && (board[k][l] & 1)) {
                        ++neighbors;
                    }
                }
            }
            if ((board[i][j] & 1) && (neighbors == 2 || neighbors == 3) || !(board[i][j] & 1) && neighbors == 3) {
                board[i][j] |= 2;
            }
        }
    }
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            board[i][j] >>= 1;
        }
    }
}
