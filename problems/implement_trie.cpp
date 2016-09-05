// Implement a trie with insert, search, and startsWith methods.

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

#include <vector>
#include <string>

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

private:
    TrieNode* root;
};
