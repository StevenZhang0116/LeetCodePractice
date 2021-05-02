class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	m_ = vector<int>(target + 1, -1);
    	m_[0] = 1;
    	return dp(nums, target);
    }
private:
	int dp(const vector<int>& nums, int target){
		if(target < 0) return 0; 
		if(m_[target] != -1) return m_[target];
		int ans = 0;
		for(const int num: nums){
			ans += dp(nums, target - num);
		}
		return m_[target] = ans;
	}
	vector<int> m_;
};