// class Solution {
// public:
//     vector<vector<int>> combine(int n, int k) {
//     	vector<vector<int>> ans;
//     	vector<int> cur;
//     	function<void(int)> dfs = [&](int s){
//     		if(cur.size() == k){
//     			ans.push_back(cur);
//     			return;
//     		}
//     		for(int i = s; i < n; ++i){
//     			cur.push_back(i + 1);
//     			dfs(i+1);
//     			cur.pop_back();
//     		}
//     	};
//     	dfs(0);
//     	return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(n, k, 1, res, curr);
        return res;
    }
private:
    void helper(int n, int k, int i, vector<vector<int>>& res, vector<int>& curr) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }
        for (int j = i; j <= n; ++j) {
            curr.push_back(j);
            helper(n, k, j+1, res, curr);
            curr.pop_back();
        }
    }
};