class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	if(matrix.empty()) return 0; 
    	m_ = matrix.size();
    	n_ = matrix[0].size();
    	dp_ = vector<vector<int>>(m_, vector<int>(n_, -1));
    	int ans = 0; 
    	for(int y = 0; y < m_; ++y){
    		for(int x = 0; x < n_; ++x){
    			ans = max(ans, dfs(matrix, x, y));
    		}
    	}
    	return ans;
   	}

private:
	int dfs(const vector<vector<int>>& mat, int x, int y){
		if(dp_[y][x] != -1) return dp_[y][x];
		static int dirs[] = {0, -1, 0, 1, 0};
		dp_[y][x] = 1;
		for(int i = 0; i < 4; ++i){
			int tx = x + dirs[i];
			int ty = y + dirs[i+1];
			if(tx < 0 || ty < 0 || tx >= n_ || ty >= m_ || mat[ty][tx] <= mat[y][x]){
				continue;
			}
			dp_[y][x] = max(dp_[y][x], 1 + dfs(mat, tx, ty));
		}
		return dp_[y][x];
    }

    int m_; 
    int n_;
    vector<vector<int>> dp_;
};