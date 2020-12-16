class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0] * m for _ in range(n)]
        for j in range(m):
            dp[0][j] = 1
        for i in range(n):
            dp[i][0] = 1
        
        for i in range(1, n):
            for j in range(1, m):
                dp[i][j] = dp[i-1][j]+dp[i][j-1]
        return dp[i][j]

