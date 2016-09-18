// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators.
// The valid operators are +, - and *.

// Example 1
// Input: "2-1-1".
// ((2-1)-1) = 0
// (2-(1-1)) = 2
// Output: [0, 2]

// Example 2
// Input: "2*3-4*5"
// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10
// Output: [-34, -14, -10, -10, 10]

#include <string>
#include <vector>

using namespace std;

vector<int> DiffWaysToCompute(const string &input) {
    if (input.empty())
        return vector<int>();
    vector<int> nums;
    vector<char> ops;
    int num = 0;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] >= '0' && input[i] <= '9') {
            num = num * 10 + input[i] - '0';
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
            nums.push_back(num);
            num = 0;
            ops.push_back(input[i]);
        }
    }
    nums.push_back(num);
    int n = nums.size();
    vector<vector<vector<int>>> results(n, vector<vector<int>>(n));
    for (int i = 0; i < n; ++i)
        results[i][i].push_back(nums[i]);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            for (int k = j; k < j + i; ++k) {
                for (auto p = results[j][k].begin(); p != results[j][k].end(); ++p) {
                    for (auto q = results[k + 1][j + i].begin(); q != results[k + 1][j + i].end(); ++q) {
                        switch (ops[k]) {
                            case '+': results[j][j + i].push_back(*p + *q); break;
                            case '-': results[j][j + i].push_back(*p - *q); break;
                            case '*': results[j][j + i].push_back(*p * *q); break;
                        }
                    }
                }
            }
        }
    }
    return results[0][n - 1];
}

