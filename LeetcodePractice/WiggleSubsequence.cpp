// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//     	nums.erase(unique(nums.begin(), nums.end()), nums.end());
//     	if(nums.size() <= 2) return nums.size();
//     	int res = 2;
//     	for(int i = 1; i < nums.size() - 1; ++i){
//     		int a = nums[i-1];
//     		int b = nums[i];
//     		int c = nums[i+1];
//     		if (b > a && b > c || b < a && b < c) res++;
//     	}
//     	return res;      
//     }
// };


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	int n = nums.size();
    	if(n <= 1) return n;
    	int inc = 1;
    	int dec = 1;
    	for(int i = 1; i < n; ++i){
    		if(nums[i] > nums[i-1]) inc = dec + 1;
    		else if(nums[i] < nums[i-1]) dec = inc + 1;
     	}
     	return max(inc, dec);
    }
};