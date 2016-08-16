// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit.
// You may complete at most two transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <vector>
#include <algorithm>

using namespace std;

int MaxProfit(const vector<int> &prices) {
    if (prices.empty())
        return 0;
    int buy1 = -prices[0], sell1 = 0, buy2 = -prices[0], sell2 = 0;
    for (int i = 1; i < prices.size(); ++i) {
        sell2 = max(sell2, prices[i] + buy2);
        buy2 = max(buy2, sell1 - prices[i]);
        sell1 = max(sell1, prices[i] + buy1);
        buy1 = max(buy1, -prices[i]);
    }
    return sell2;
}
