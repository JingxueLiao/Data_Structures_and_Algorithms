// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

// Your algorithm should run in O(n) complexity.

#include <vector>
#include <unordered_map>

using namespace std;

int LongestConsecutive(const vector<int> &nums) {
    int longest = 0;
    unordered_map<int, int> lengths;
    for (auto p = nums.begin(); p != nums.end(); ++p) {
        if (lengths.find(*p) != lengths.end())
            continue;
        if (lengths.find(*p - 1) != lengths.end() && lengths.find(*p + 1) != lengths.end()) {
            lengths[*p - lengths[*p - 1]] = lengths[*p + lengths[*p + 1]] = lengths[*p] = lengths[*p - 1] + 1 + lengths[*p + 1];
        } else if (lengths.find(*p - 1) != lengths.end()) {
            lengths[*p - lengths[*p - 1]] = lengths[*p] = lengths[*p - 1] + 1;
        } else if (lengths.find(*p + 1) != lengths.end()) {
            lengths[*p + lengths[*p + 1]] = lengths[*p] = lengths[*p + 1] + 1;
        } else {
            lengths[*p] = 1;
        }
        if (longest < lengths[*p])
            longest = lengths[*p];
    }
    return longest;
}
