dp = [[0]*3 for _ in range(10001)]
dp[1] = [1, 0, 0]
dp[2] = [1, 1, 0]
dp[3] = [1, 1, 1]

cands = []
for _ in range(int(input())):
    cands.append(int(input()))

for n in range(4, max(cands)+1):
    dp[n][0] = dp[n-1][0]
    dp[n][1] = dp[n-2][0] + dp[n-2][1]
    dp[n][2] = dp[n-3][0] + dp[n-3][1] + dp[n-3][2]

for c in cands:
    print(sum(dp[c]))
