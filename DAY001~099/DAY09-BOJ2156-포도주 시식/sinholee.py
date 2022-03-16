n = int(input())

dp = [[0, 0, 0] for _ in range(n)]

wines = [0] * n
for i in range(n):
    wine = int(input())
    wines[i] = wine


dp[0][0] = wines[0]  # 나 자신을 마시고, 그 전을 안 마신 최대값
dp[0][1] = wines[0]  # 나 자신을 마시고, 그 전을 마신 최대값
dp[0][2] = 0  # 나 자신을 안마시고 최대값

for i in range(1, n):
    dp[i][0] = dp[i-1][1] + wines[i]
    dp[i][1] = dp[i-1][2] + wines[i]
    dp[i][2] = max(dp[i-1])


print(max(dp[n-1]))

