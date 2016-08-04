// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
// You have the following 3 operations permitted on a word:
// a) Insert a character
// b) Delete a character
// c) Replace a character

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int MinDistance(const string &word1, const string &word2) {
    vector<int> distances(word2.size() + 1);
    for (int i = 1; i <= word2.size(); ++i)
        distances[i] = i;
    for (int i = 0; i < word1.size(); ++i) {
        int pre = distances[0];
        distances[0] = i + 1;
        for (int j = 0; j < word2.size(); ++j) {
            int tmp = distances[j + 1];
            distances[j + 1] = min(pre, min(distances[j], distances[j + 1])) + 1;
            if (word1[i] == word2[j])
                distances[j + 1] = min(pre, distances[j + 1]);
            pre = tmp;
        }
    }
    return distances[word2.size()];
}
