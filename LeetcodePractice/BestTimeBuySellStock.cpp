class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    	const int N = prices.size();
    	int cash = 0;
    	int hold = -prices[0];
    	for(int i = 1; i < N; ++i){
    		cash = max(cash, prices[i] + hold - fee);
    		hold = max(hold, cash - prices[i]);
    	}
    	return cash;
    }
};