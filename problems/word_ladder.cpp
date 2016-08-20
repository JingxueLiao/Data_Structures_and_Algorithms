// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 
//   1.Only one letter can be changed at a time
//   2.Each intermediate word must exist in the word list
 
// For example,
// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
 
// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.

#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

int LadderLength(const string &beginWord, const string &endWord, const unordered_set<string> &wordList) {
    if (beginWord.empty() || endWord.empty() || beginWord.size() != endWord.size() || wordList.empty())
        return 0;
    if (beginWord == endWord)
        return 1;
    int length = 2;
    queue<string> level;
    unordered_set<string> appeared;
    level.push(beginWord);
    appeared.insert(beginWord);
    while (!level.empty()) {
        int n = level.size();
        while (n--) {
            string cur = level.front();
            level.pop();
            for (int i = 0; i < cur.size(); ++i) {
                char c = cur[i];
                for (char j = 'a'; j <= 'z'; ++j) {
                    cur[i] = j;
                    if (cur == endWord)
                        return length;
                    if (wordList.find(cur) != wordList.end() && appeared.find(cur) == appeared.end()) {
                        level.push(cur);
                        appeared.insert(cur);
                    }
                }
                cur[i] = c;
            }
        }
        ++length;
    }
    return 0;
}
