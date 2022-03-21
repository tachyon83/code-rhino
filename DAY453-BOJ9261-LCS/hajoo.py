s1 = '0' + input()
s2 = '0' + input()

dp = [[0] * len(s2) for _ in range(len(s1))]
ans = 0

for i in range(1, len(s1)):
    for j in range(1, len(s2)):
        dp[i][j] = max(dp[i - 1][j - 1] + (s1[i] == s2[j]), dp[i - 1][j], dp[i][j - 1])
        ans = max(ans, dp[i][j])

print(ans)
