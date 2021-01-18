import sys
import copy
si = sys.stdin.readline

n = int(si())
dp = [[[0, 0, 0]for _ in range(4)] for _ in range(100)]
dp[0][0] = [1, 0, 0]
dp[0][1] = [0, 0, 0]
dp[0][2] = [0, 0, 0]
dp[0][3] = [0, 0, 0]

for i in range(n):
    if not i:
        continue
    for j in range(4):
        if dp[i][0][0] < dp[i-1][j][0]+1:
            dp[i][0] = copy.deepcopy(dp[i-1][j])
            dp[i][0][0] += 1
        if dp[i][1][1] < dp[i-1][j][0]:
            dp[i][1] = copy.deepcopy(dp[i-1][j])
            dp[i][1][1] = dp[i][1][0]
        if dp[i][2][2] < dp[i-1][j][1]:
            dp[i][2] = copy.deepcopy(dp[i-1][j])
            dp[i][2][2] = dp[i-1][j][1]
        if dp[i][3][0] < dp[i-1][j][0]+dp[i-1][j][2]:
            dp[i][3] = copy.deepcopy(dp[i-1][j])
            dp[i][3][0] += dp[i-1][j][2]

m = 0
for i in range(4):
    m = max(m, dp[n-1][i][0])
print(m)
