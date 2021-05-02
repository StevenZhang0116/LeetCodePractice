// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//     	const int n = nums.size();
//     	vector<int> l(n, 1);
//     	vector<int> r(n, 1);
//     	vector<int> ans(n);
//     	for(int i = 1; i < n; ++i){
//     		l[i] = l[i-1] * nums[i-1];
//     	}
//     	for(int i = n - 2; i >= 0; --i){
//     		r[i] = r[i+1] * nums[i+1];
//     	}
//     	for(int i = 0; i < n; ++i){
//     		ans[i] = l[i] * r[i];
//     	}
//     	return ans;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
                
        
        int n = nums.size();
        
        vector<int> ls(n+2);
        vector<int> rs(n+2);
        
        ls[0] = 1;
        rs[n+1] = 1;
        
        int lsProduct = 1;
        int rsProduct = 1;
        
        for (int i = 0, j = n-1; i < n-1 && j > 0; ++i, --j)
        {
            lsProduct *=  nums[i];
            ls[i+1] = lsProduct;
            
            rsProduct *= nums[j];
            rs[j+1] = rsProduct;
        }
        
        
        vector<int> result(n);        
        for (int i = 0; i < n; ++i)
        {
            result[i] = ls[i] * rs[i+2];
        }
        
        
        return result;
    }
};