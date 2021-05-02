class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
    	constexpr long kmod = 1000000007;
    	std::sort(arr.begin(), arr.end());
    	unordered_map<int, long> dp;
    	for(int i = 0; i < arr.size(); ++i){
    		dp[arr[i]] = 1;
    		for(int j = 0; j < i; ++j){
    			if(arr[i] % arr[j] == 0 && dp.count(arr[i] / arr[j])){
    				dp[arr[i]] += (dp[arr[j]] * dp[arr[i] / arr[j]]) % kmod;

    			}
    		}
    	}
    	long ans = 0;
    	for(const auto& kv: dp){
    		ans += kv.second;
    	}
    	return ans % kmod;
    }
};