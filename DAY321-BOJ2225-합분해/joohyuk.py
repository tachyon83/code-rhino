import sys
si, mod = sys.stdin.readline, int(1e9)

n, k = [int(e) for e in si().split()]
dp = [[0 for _ in range(k+1)]for _ in range(n+1)]
dp[0][0] = 1

for v in range(n+1):
    for i in range(n+1):
        for j in range(1, k+1):
            if v+i <= n:
                dp[v+i][j] += dp[v][j-1]
                dp[v+i][j] %= mod
print(dp[n][k])
