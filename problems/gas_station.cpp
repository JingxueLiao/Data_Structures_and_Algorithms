// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
// You begin the journey with an empty tank at one of the gas stations.
// Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

// Note:
// The solution is guaranteed to be unique.

#include <vector>

using namespace std;

int CanCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    if (gas.size() != cost.size())
        return -1;
    if (gas.empty() || cost.empty())
        return 0;
    int n = gas.size();
    int i = 0, j = 1 % n;
    int left = gas[0] - cost[0];
    while (i != j) {
        while (i != j && left >= 0) {
            left += gas[j] - cost[j];
            j = (j + 1) % n;
        }
        while (i != j && left < 0) {
            i = (i + n - 1) % n;
            left += gas[i] - cost[i];
        }
    }
    return left < 0 ? -1 : i;
}
