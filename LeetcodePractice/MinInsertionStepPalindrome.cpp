// class Solution {
// public:
//     int minInsertions(string s) {
//     	const int n = s.length();
//     	vector<vector<int>> dp(n, vector<int>(n));
//     	for(int l = 2; l <= n; ++l){
//     		for(int i = 0, j = l - 1; j < n; ++i, ++j){
//     			dp[i][j] = s[i] == s[j] ? dp[i+1][j-1]: min(dp[i+1][j], dp[i][j-1]) + 1; 
//     		}
//     	}
//     	return dp[0][n-1];
//     }
// };


class Solution {
public:
    int minInsertions(string s) {
      int n = s.size();
      int dp[2][n+1];
      memset(dp, 0, sizeof(dp));
      for (int i = n-1; i >= 0; --i) {
        int now = i&1;
        for (int j = i + 1; j < n; ++j) {
          dp[now][j] = min(dp[now^1][j]+1, dp[now][j-1]+1);
          if (s[i] == s[j]) {
            dp[now][j] = min(dp[now][j], dp[now^1][j-1]);
          }
        }
      }
      return dp[0][n-1];
    }
};