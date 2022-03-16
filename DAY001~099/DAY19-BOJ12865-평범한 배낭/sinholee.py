import sys
si = sys.stdin.readline

n, k = map(int, si().split())
stuffs = [tuple(map(int, si().split())) for _ in range(n)]
dp = [[0] * (k+1) for _ in range(n)]

for j in range(k+1):
    if j >= stuffs[0][0]:
        dp[0][j] = stuffs[0][1]
for i in range(1, n):
    for j in range(k+1):
        w, v = stuffs[i]
        dp[i][j] = dp[i-1][j]
        if j >= w :
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v)

print(dp[n-1][k])
