class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        dp = []
        for i in range(len(A)):
        	dp.append([0] * len(B))

        for i in range(len(A)):
        	for j in range(len(B)):
        		if A[i] == B[j]:
        			dp[i][j] = max(dp[i][j], 1)
        			if i - 1 >= 0 and j - 1 >= 0:
        				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1)
        		else:
        			if i - 1 >= 0 and j - 1 >= 0:
        				dp[i][j] = max(dp[i][j], dp[i-1][j-1])
        			if j - 1 >= 0:
        				dp[i][j] = max(dp[i][j], dp[i][j-1])
        			if i - 1 >= 0:
        				dp[i][j] = max(dp[i][j], dp[i-1][j])
        			
        return dp[-1][-1]