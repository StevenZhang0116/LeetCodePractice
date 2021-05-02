class Solution {
public:
    int kInversePairs(int n, int k) {
    	long long mod = 1000000007;
    	if (k < 0 || k > n * (n - 1)/2) return 0;
    	if (k == 0 || k > n * (n - 1)/2) return 1;
    	vector<vector<long long>> dp(n+1, vector<long long>(k+1,0));
    	dp[2][0] = 1;
    	dp[2][1] = 1;
    	for(int i = 3; i <= n; ++i){
    		dp[i][0] = 1;
    		for(int j = 1; j <= min(k, i*(i-1)/2); ++j){
    			dp[i][j] = dp[i][j-1] + dp[i-1][j];
    			if(j >= i){
    				dp[i][j] -= dp[i-1][j-i];
    			} 
    			dp[i][j] = (dp[i][j] + mod) % mod;
    		}
    	}
    	return static_cast<int>(dp[n][k]);
    }
};