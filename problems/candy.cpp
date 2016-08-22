// There are N children standing in a line.
// Each child is assigned a rating value.
// You are giving candies to these children subjected to the following requirements:
//   1. Each child must have at least one candy.
//   2. Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?

#include <vector>
#include <algorithm>

using namespace std;

int Candy(const vector<int> &ratings) {
    int sum = 0;
    int prev = 1, peak = 0;
    for (int i = 1; i < ratings.size(); ++i) {
        if (ratings[i - 1] < ratings[i]) {
            if (peak) {
                sum += max(prev, peak);
                peak = 0;
                prev = 2;
            } else {
                sum += prev++;
            }
        } else if (ratings[i] < ratings[i - 1]) {
            if (peak == 0) {
                peak = prev;
                prev = 1;
            }
            sum += prev++;
        } else {
            sum += max(prev, peak);
            prev = 1;
            peak = 0;
        }
    }
    sum += max(prev, peak);
    return sum;
}
