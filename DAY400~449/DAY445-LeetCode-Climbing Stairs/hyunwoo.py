# dp 문제

class Solution:
    def climbStairs(self, n: int) -> int:
        # dp[i] : i번째 계단까지 올라가는 경우의 수
        dp = [-1 for _ in range(50)]
        dp[1] = 1
        dp[2] = 2
        for i in range(3, 50):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
