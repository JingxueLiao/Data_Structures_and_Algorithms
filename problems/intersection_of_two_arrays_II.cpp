// Given two arrays, write a function to compute their intersection.

// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

// Note:
// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.

// Follow up:
// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

#include <vector>
#include <unordered_set>

using namespace std;

vector<int> Intersect(const vector<int> &nums1, const vector<int> &nums2) {
    vector<int> result;
    unordered_multiset<int> set1;
    for (auto p = nums1.begin(); p != nums1.end(); ++p)
        set1.insert(*p);
    for (auto p = nums2.begin(); p != nums2.end(); ++p) {
        if (set1.find(*p) != set1.end()) {
            result.push_back(*p);
            set1.erase(set1.find(*p));
        }
    }
    return result;
}
