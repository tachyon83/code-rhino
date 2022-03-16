import sys
si = sys.stdin.readline

n, m = [int(e) for e in si().split()]
cons = [[set()for _ in range(m+1)]for _ in range(n+1)]
dp = [[0 for _ in range(m+1)]for _ in range(n+1)]
dp[0][0] = 1
t = int(si())
while t:
    t -= 1
    a, b, c, d = [int(e) for e in si().split()]
    if a < c or b < d:cons[a][b].add((c, d))
    else:cons[c][d].add((a, b))

for i in range(n):
    for j in range(m):
        if (i, j+1) not in cons[i][j]:
            dp[i][j+1] += dp[i][j]
    for j in range(m+1):
        if (i+1, j) not in cons[i][j]:
            dp[i+1][j] += dp[i][j]
for j in range(m):
    if (i, j+1) not in cons[i][j]:
        dp[n][j+1] += dp[n][j]
print(dp[n][m])
