// visit
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/75927/share-my-thinking-process/
// for a gorgeous solution and explaination.

#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<int> buy(prices.size() + 1), sell(prices.size() + 1),
			rest(prices.size() + 1);
		buy[0] = -prices[0];
		sell[0] = 0;
		rest[0] = 0;
		for(int i = 1; i < prices.size(); ++i) {
			buy[i] = max(buy[i - 1], rest[i - 1] - prices[i]);
			sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
			rest[i] = max(sell[i - 1], rest[i - 1]);
		}
		return sell[prices.size() - 1];
	}
};