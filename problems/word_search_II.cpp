// Given a 2D board and a list of words from the dictionary, find all words in the board.
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once in a word.

// For example,
// Given words = ["oath","pea","eat","rain"] and board =
// [
  // ['o','a','a','n'],
  // ['e','t','a','e'],
  // ['i','h','k','r'],
  // ['i','f','l','v']
// ]
// Return ["eat","oath"].

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : next(26), isWord(false) {
    }

    vector<TrieNode *> next;
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(const string &word) {
        TrieNode *cur = root;
        for (auto p = word.begin(); p != word.end(); ++p) {
            if (cur->next[*p - 'a'] == nullptr)
                cur->next[*p - 'a'] = new TrieNode();
            cur = cur->next[*p - 'a'];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(const string &word) {
        TrieNode *cur = root;
        for (auto p = word.begin(); p != word.end(); ++p) {
            if (cur->next[*p - 'a'] == nullptr)
                return false;
            cur = cur->next[*p - 'a'];
        }
        return cur->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(const string &prefix) {
        TrieNode *cur = root;
        for (auto p = prefix.begin(); p != prefix.end(); ++p) {
            if (cur->next[*p - 'a'] == nullptr)
                return false;
            cur = cur->next[*p - 'a'];
        }
        return true;
    }

    TrieNode* root;
};

void Find(unordered_set<string> &found, string &word, const vector<vector<char>> &board, int row, int column, vector<vector<bool>> &visited, TrieNode *cur) {
    if (visited[row][column] || cur == nullptr)
        return;
    word.push_back(board[row][column]);
    if (cur->isWord)
        found.insert(word);
    visited[row][column] = true;
    if (row > 0)
        Find(found, word, board, row - 1, column, visited, cur->next[board[row - 1][column] - 'a']);
    if (column < board[0].size() - 1)
        Find(found, word, board, row, column + 1, visited, cur->next[board[row][column + 1] - 'a']);
    if (row < board.size() - 1)
        Find(found, word, board, row + 1, column, visited, cur->next[board[row + 1][column] - 'a']);
    if (column > 0)
        Find(found, word, board, row, column - 1, visited, cur->next[board[row][column - 1] - 'a']);
    visited[row][column] = false;
    word.pop_back();
}

vector<string> FindWords(const vector<vector<char>> &board, const vector<string> &words) {
    if (board.empty() || board[0].empty() || words.empty())
        return vector<string>();
    Trie trie;
    for (auto p = words.begin(); p != words.end(); ++p)
        trie.insert(*p);
    TrieNode *root = trie.root;
    unordered_set<string> found;
    string word;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board[0].size(); ++j)
            Find(found, word, board, i, j, visited, root->next[board[i][j] - 'a']);
    return vector<string>(found.begin(), found.end());
}
