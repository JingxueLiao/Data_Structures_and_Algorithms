// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// The update(i, val) function modifies nums by updating the element at index i to val.

// Example:
// Given nums = [1, 3, 5]

// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8

// Note:
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.

#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(const vector<int> &nums) {
        n = 1;
        while (n < nums.size())
            n *= 2;
        sums.resize(2 * n - 1);
        for (int i = 0; i < nums.size(); ++i)
            sums[n - 1 + i] = nums[i];
        for (int i = n - 2; i >= 0; --i)
            sums[i] = sums[2 * i + 1] + sums[2 * i + 2];
    }

    void update(int i, int val) {
        i = n - 1 + i;
        sums[i] = val;
        while (i) {
            i = (i - 1) / 2;
            sums[i] = sums[2 * i + 1] + sums[2 * i + 2];
        }
    }

    int sumRange(int i, int j) {
        return query(0, i, j + 1, 0, n);
    }

private:
    int n;
    vector<int> sums;

    int query(int i, int begin, int end, int left, int right) {
        if (begin == left && end == right) {
            return sums[i];
        } else {
            int mid = left + (right - left) / 2;
            if (end <= mid) {
                return query(2 * i + 1, begin, end, left, mid);
            } else if (mid <= begin) {
                return query(2 * i + 2, begin, end, mid, right);
            } else {
                return query(2 * i + 1, begin, mid, left, mid) + query(2 * i + 2, mid, end, mid, right);
            }
        }
    }
};

#include <iostream>

int main() {
    vector<int> nums{1, 3, 5};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 1) << endl;
    numArray.update(1, 10);
    cout << numArray.sumRange(1, 2) << endl;
}
