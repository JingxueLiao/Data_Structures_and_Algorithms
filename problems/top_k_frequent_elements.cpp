// Given a non-empty array of integers, return the k most frequent elements.

// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

void Select(vector<pair<int, int>> &frequents, int begin, int end, int k) {
    if (begin == end)
        return;
    pair<int, int> pivot = frequents[begin];
    int i = begin, j = end - 1;
    while (i < j) {
        while (i < j && frequents[j].first < pivot.first)
            --j;
        if (i < j)
            swap(frequents[i++], frequents[j]);
        while (i < j && frequents[i].first > pivot.first)
            ++i;
        if (i < j)
            swap(frequents[i], frequents[j--]);
    }
    frequents[i] = pivot;
    if (i - begin + 1 < k) {
        Select(frequents, i + 1, end, k - (i - begin + 1));
    } else if (i - begin + 1 > k) {
        Select(frequents, begin, i, k);
    }
}

vector<int> TopKFrequent(const vector<int> &nums, int k) {
    unordered_map<int, int> counts;
    for (auto p = nums.begin(); p != nums.end(); ++p)
        ++counts[*p];
    vector<pair<int, int>> frequents;
    for (auto p = counts.begin(); p != counts.end(); ++p)
        frequents.push_back(make_pair(p->second, p->first));
    Select(frequents, 0, frequents.size(), k);
    vector<int> topk;
    for (int i = 0; i < k; ++i)
        topk.push_back(frequents[i].second);
    return topk;
}
