class Solution {
public:
    int maxCoins(vector<int>& piles) {
    	const int n = piles.size() / 3;
    	sort(begin(piles), end(piles));
    	int ans = 0; 
    	for(int i = 0; i < n; ++i){
    		ans += piles[n*3 - 2 - i*2];
    	}
    	return ans;
    }
};