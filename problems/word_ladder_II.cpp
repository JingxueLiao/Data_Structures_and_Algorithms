// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
// 
//   1.Only one letter can be changed at a time
//   2.Each intermediate word must exist in the word list
// 
// For example,
// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// Return
//   [
//     ["hit","hot","dot","dog","cog"],
//     ["hit","hot","lot","log","cog"]
//   ]
//   
// Note:
// All words have the same length.
// All words contain only lowercase alphabetic characters.

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void FindPath(unordered_map<string, vector<string>> &tree, const string &beginWord, const string &endWord, vector<vector<string>> &paths, vector<string> &cur) {
    cur.push_back(beginWord);
    if (beginWord == endWord) {
        paths.push_back(cur);
    } else {
        for (auto p = tree[beginWord].begin(); p != tree[beginWord].end(); ++p)
            FindPath(tree, *p, endWord, paths, cur);
    }
    cur.pop_back();
}

unordered_set<string> BuildTree(unordered_set<string> &pos, unordered_set<string> &neg, unordered_map<string, vector<string>> &tree, const unordered_set<string> &wordList) {
    unordered_set<string> junctions;
    unordered_set<string> next;
    while (junctions.empty() && !pos.empty() && !neg.empty()) {
        for (auto p = pos.begin(); p != pos.end(); ++p) {
            if (tree.find(*p) != tree.end()) {
                continue;
            } else {
                string word = *p;
                for (int i = 0; i < word.size(); ++i) {
                    char c = word[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        word[i] = j;
                        if (wordList.find(word) != wordList.end() && pos.find(word) == pos.end() && tree.find(word) == tree.end()) {
                            next.insert(word);
                            tree[*p].push_back(word);
                            if (neg.find(word) != neg.end())
                                junctions.insert(word);
                        }
                    }
                    word[i] = c;
                }
            }
        }
        if (!junctions.empty())
            break;
        swap(pos, next);
        next.clear();
        for (auto p = neg.begin(); p != neg.end(); ++p) {
            if (tree.find(*p) != tree.end()) {
                continue;
            } else {
                string word = *p;
                for (int i = 0; i < word.size(); ++i) {
                    char c = word[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        word[i] = j;
                        if (wordList.find(word) != wordList.end() && neg.find(word) == neg.end() && tree.find(word) == tree.end()) {
                            next.insert(word);
                            tree[*p].push_back(word);
                            if (pos.find(word) != pos.end())
                                junctions.insert(word);
                        }
                    }
                    word[i] = c;
                }
            }
        }
        swap(neg, next);
        next.clear();
    }
    return junctions;
}

vector<vector<string>> FindLadders(const string &beginWord, const string &endWord, const unordered_set<string> &wordList) {
    if (beginWord.empty() || endWord.empty() || beginWord.size() != endWord.size() || wordList.empty())
        return vector<vector<string>>();
    if (beginWord == endWord)
        return vector<vector<string>>{ { beginWord } };
    vector<vector<string>> ladders;
    unordered_set<string> pos, neg;
    pos.insert(beginWord);
    neg.insert(endWord);
    unordered_map<string, vector<string>> tree;
    unordered_set<string> junctions = BuildTree(pos, neg, tree, wordList);
    for (auto p = junctions.begin(); p != junctions.end(); ++p) {
        vector<vector<string>> pos_paths, neg_paths;
        vector<string> cur;
        FindPath(tree, beginWord, *p, pos_paths, cur);
        FindPath(tree, endWord, *p, neg_paths, cur);
        for (auto q1 = pos_paths.begin(); q1 != pos_paths.end(); ++q1) {
            for (auto q2 = neg_paths.begin(); q2 != neg_paths.end(); ++q2) {
                ladders.push_back(vector<string>());
                vector<string> &tmp = ladders.back();
                tmp.insert(tmp.end(), q1->begin(), q1->end());
                tmp.insert(tmp.end(), q2->rbegin() + 1, q2->rend());
            }
        }
    }
    return ladders;
}
