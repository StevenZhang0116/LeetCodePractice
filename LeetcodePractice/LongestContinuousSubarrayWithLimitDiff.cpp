class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
    	deque<int> max_q;
    	deque<int> min_q;
    	int ans = 0;
    	int ind = 0;
    	for(int i = 0; i < nums.size(); ++i){
    		while(!min_q.empty() && nums[i] < min_q.back()){
    			min_q.pop_back();
    		}
    		while(!max_q.empty() && nums[i] > max_q.back()){
    			max_q.pop_back();
    		}
    		min_q.push_back(nums[i]);
    		max_q.push_back(nums[i]);
    		while(max_q.front() - min_q.front() > limit){
    			if(max_q.front() == nums[ind]) max_q.pop_front();
    			if(min_q.front() == nums[ind]) min_q.pop_front();
    			++ind;
    		}
    		ans = max(ans, i - ind + 1);
    	}
    	return ans;
    }
};