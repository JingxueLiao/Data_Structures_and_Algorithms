// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
// Note: The sequence of integers will be represented as a string.

#include <string>
#include <algorithm>

using namespace std;

string CountAndSay(int n) {
    if (n <= 0)
        return string();
    string sequence("1");
    for (int i = 1; i < n; ++i) {
        string next;
        int j = 0;
        while (j < sequence.size()) {
            int k = j;
            while (k <sequence.size() && sequence[k] == sequence[j])
                ++k;
            next.push_back('0' + k - j);
            next.push_back(sequence[j]);
            j = k;
        }
        swap(sequence, next);
    }
    return sequence;
}
