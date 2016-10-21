// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

// Example:
// prices = [1, 2, 3, 0, 2]
// maxProfit = 3
// transactions = [buy, sell, cooldown, buy, sell]

#include <vector>
#include <algorithm>

using namespace std;

int MaxProfit(const vector<int> &prices) {
    if (prices.empty())
        return 0;
    int max_buy = -prices[0];
    int ppre = 0, pre = 0;
    for (int i = 1; i < prices.size(); ++i) {
        int cur = max(pre, max_buy + prices[i]);
        max_buy = max(max_buy, ppre - prices[i]);
        ppre = pre;
        pre = cur;
    }
    return pre;
}
