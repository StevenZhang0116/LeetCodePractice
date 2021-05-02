// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//     	int n = obstacleGrid.size();
//     	if (n == 0) return 0; 
//     	int m = obstacleGrid[0].size();

//     	f_ = vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MIN));
//     	return paths(m, n, obstacleGrid);
//     }
// private:
// 	vector<vector<int>> f_;

// 	int paths(int x, int y, const vector<vector<int>>& o){
// 		if(x <= 0 || y <= 0) return 0; 
// 		if(x == 1 && y == 1) return 1 - o[0][0];
// 		if(f_[y][x] != INT_MIN) return f_[y][x];

// 		if(o[y-1][x-1] == 1){
// 			f_[y][x] = 0;
// 		}
// 		else{
// 			f_[y][x] = paths(x - 1, y, o) + paths(x, y - 1, o);
// 		}

// 		return f_[y][x];
// 	}
// };

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob)
    {int m = ob.size();
    int n = ob[0].size();
    vector<vector<int>> dp(m , vector<int>(n,0));
    dp[0][0] = 1-ob[0][0];
    for(int i = 1 ; i < m ; ++i) 
        if(ob[i][0] == 0) dp[i][0] = dp[i-1][0];
    for(int i = 1 ; i < n ;++i)
        if(ob[0][i] == 0) dp[0][i] = dp[0][i-1];
    for(int i = 1 ; i < m ; ++i){
        for(int j = 1 ; j < n ; ++j)
        {
            if(ob[i][j] == 0) dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
}
    