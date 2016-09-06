// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

// For example:
// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true

// Note:
// You may assume that all words are consist of lowercase letters a-z.

#include <string>
#include <vector>

using namespace std;

class WordDictionary {
private:
    class TrieNode {
    public:
        // Initialize your data structure here.
        TrieNode() : next(26), isWord(false) {
        }

        vector<TrieNode *> next;
        bool isWord;
    };

public:
    WordDictionary() : root(new TrieNode) {
    }

    // Adds a word into the data structure.
    void addWord(const string &word) {
        TrieNode *cur = root;
        for (auto p = word.begin(); p != word.end(); ++p) {
            if (cur->next[*p - 'a'] == nullptr)
                cur->next[*p - 'a'] = new TrieNode();
            cur = cur->next[*p - 'a'];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(const string &word) {
        return search(word, 0, root);
    }


private:
    TrieNode* root;

    bool search(const string &word, int begin, TrieNode *cur) {
        for (int i = begin; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; ++j)
                    if (cur->next[j] && search(word, i + 1, cur->next[j]))
                        return true;
                return false;
            } else if (cur->next[word[i] - 'a'] == nullptr) {
                return false;
            } 
            cur = cur->next[word[i] - 'a'];
        }
        return cur->isWord;
    }
};
