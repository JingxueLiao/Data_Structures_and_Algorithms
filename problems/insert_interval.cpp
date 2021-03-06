// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.

// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> Insert(const vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    int i = 0;
    while (i < intervals.size() && intervals[i].start <= newInterval.start)
        result.push_back(intervals[i++]);
    if (result.empty() || result.back().end < newInterval.start) {
        result.push_back(newInterval);
    } else if (result.back().end < newInterval.end) {
        result.back().end = newInterval.end;
    }
    while (i < intervals.size() && intervals[i].start <= result.back().end) {
        if (result.back().end < intervals[i].end)
            result.back().end = intervals[i].end;
        ++i;
    }
    while (i < intervals.size())
        result.push_back(intervals[i++]);
    return result;
}
