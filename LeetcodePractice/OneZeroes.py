class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for the_str in strs:
        	zeros, ones = 0, 0
        	for c in the_str:
        		if c == "0":
        			zeros += 1
        		elif c == "1":
        			ones += 1
        	for i in range(m, zeros - 1, -1):
        		for j in range(n, ones - 1, -1):
        			dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1)
        return dp[m][n] 