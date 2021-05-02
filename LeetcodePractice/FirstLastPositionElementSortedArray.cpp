class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	return {firstPos(nums, target), lastPos(nums, target)};
    }

private:
	int firstPos(const vector<int>& nums, int target){
		int l = 0;
		int r = nums.size();
		while(l < r){
			int m = l + (r - l) / 2;
			if(nums[m] >= target){
				r = m;
			}
			else{
				l = m + 1;
			}
		}

		if(l == nums.size() || nums[l] != target) return -1;
		return l;
	}

	int lastPos(const vector<int>& nums, int target){
		int l = 0;
		int r = nums.size();
		while(l < r){
			int m = l + (r - l) / 2;
			if(nums[m] > target){
				r = m;
			}
			else{
				l = m + 1;
			}
		}

		--l;
		if(l < 0 || nums[l] != target) return -1;
		return l;
	}
};