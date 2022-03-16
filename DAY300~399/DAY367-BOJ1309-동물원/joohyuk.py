import sys
si = sys.stdin.readline

n, mod = int(si()), 9901
dp = [[0, 0, 0]for _ in range(n)]
dp[0] = [1, 1, 1]

for i in range(n-1):
    dp[i+1][0] = (dp[i][0]+dp[i][1]+dp[i][2]) % mod
    dp[i+1][1] = (dp[i][0]+dp[i][2]) % mod
    dp[i+1][2] = (dp[i][0]+dp[i][1]) % mod
print(sum(dp[n-1]) % mod)
