// Given two arrays, write a function to compute their intersection.

// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

// Note:
// Each element in the result must be unique.
// The result can be in any order.

#include <vector>
#include <unordered_set>

using namespace std;

vector<int> Intersection(const vector<int> &nums1, const vector<int> &nums2) {
    vector<int> result;
    unordered_set<int> set1;
    for (auto p = nums1.begin(); p != nums1.end(); ++p)
        set1.insert(*p);
    for (auto p = nums2.begin(); p != nums2.end(); ++p) {
        if (set1.find(*p) != set1.end()) {
            result.push_back(*p);
            set1.erase(*p);
        }
    }
    return result;
}
