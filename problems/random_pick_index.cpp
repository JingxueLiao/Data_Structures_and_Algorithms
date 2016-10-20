// Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

// Note:
// The array size can be very large. Solution that uses too much extra space will not pass the judge.

// Example:

// int[] nums = new int[] {1,2,3,3,3};
// Solution solution = new Solution(nums);

// // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
// solution.pick(3);

// // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
// solution.pick(1);

#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class RandomPickIndex {
public:
    RandomPickIndex(vector<int> nums) {
        swap(nums, nums_);
        srand(time(nullptr));
    }

    int pick(int target) {
        int index = -1;
        int total = 0;
        for (int i = 0; i < nums_.size(); ++i) {
            if (nums_[i] == target) {
                ++total;
                if (rand() % total == 0)
                    index = i;
            }
        }
        return index;
    }

private:
    vector<int> nums_;
};
