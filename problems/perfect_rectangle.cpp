// Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

// Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).


// Example 1:

// rectangles = [
  // [1,1,3,3],
  // [3,1,4,2],
  // [3,2,4,4],
  // [1,3,2,4],
  // [2,3,3,4]
// ]

// Return true. All 5 rectangles together form an exact cover of a rectangular region.

// Example 2:

// rectangles = [
  // [1,1,2,3],
  // [1,3,2,4],
  // [3,1,4,2],
  // [3,2,4,4]
// ]

// Return false. Because there is a gap between the two rectangular regions.

// Example 3:

// rectangles = [
  // [1,1,3,3],
  // [3,1,4,2],
  // [1,3,2,4],
  // [3,2,4,4]
// ]

// Return false. Because there is a gap in the top center.

// Example 4:

// rectangles = [
  // [1,1,3,3],
  // [3,1,4,2],
  // [1,3,2,4],
  // [2,2,4,4]
// ]

// Return false. Because two of the rectangles overlap with each other.

#include <vector>
#include <functional>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

class PointHash {
public:
    size_t operator()(const pair<int, int> &point) const {
        static hash<int> h;
        size_t l = h(point.first), r = h(point.second);
        return l + 0x9e3779b9 + (r << 6) + (r >> 2);
    }
};

bool IsRectangleCover(const vector<vector<int>> &rectangles) {
    if (rectangles.empty())
        return true;
    unordered_map<pair<int, int>, int, PointHash> points;
    int area = 0;
    int left = INT_MAX, right = INT_MIN, bottom = INT_MAX, top = INT_MIN;
    for (int i = 0; i < rectangles.size(); ++i) {
        int x1 = rectangles[i][0], y1 = rectangles[i][1], x2 = rectangles[i][2], y2 = rectangles[i][3];
        left = min(left, x1);
        right = max(right, x2);
        bottom = min(bottom, y1);
        top = max(top, y2);
        area += (x2 - x1) * (y2 - y1);
        ++points[make_pair(x1, y1)];
        ++points[make_pair(x1, y2)];
        ++points[make_pair(x2, y2)];
        ++points[make_pair(x2, y1)];
    }
    if (area != (right - left) * (top - bottom))
        return false;
    int corner = 0;
    for (auto p = points.begin(); p != points.end(); ++p) {
        if (p->second == 1) {
            if (p->first.first != left && p->first.first != right || p->first.second != bottom && p->first.second != top)
                return false;
            else
                ++corner;
        } else if (p->second != 2 && p->second != 4) {
            return false;
        }
    }
    return corner == 4;
}
