// Given a sorted integer array without duplicates, return the summary of its ranges.
// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

#include <vector>
#include <string>

using namespace std;

vector<string> SummaryRanges(const vector<int> &nums) {
    if (nums.empty())
        return vector<string>();
    vector<string> ranges;
    unsigned int i = 0, j = 0;
    while (i < nums.size()) {
        j = i;
        while (j < nums.size() - 1 && nums[j] + 1 == nums[j + 1])
            ++j;
        string range;
        if (j != i)
            range = to_string(nums[i]) + "->" + to_string(nums[j]);
        else
            range = to_string(nums[i]);
        ranges.push_back(range);
        i = j + 1;
    }
    return ranges;
}
