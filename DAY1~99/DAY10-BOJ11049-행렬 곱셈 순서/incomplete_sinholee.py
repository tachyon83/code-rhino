n = int(input())

mat = [list(map(int, input().split())) for _ in range(n)]


dp = [[0, [0, 0]] for _ in range(n)]

dp[0][0] = mat[0][0] * mat[0][1]
dp[0][1][0] = mat[0][0]
dp[0][1][1] = mat[0][1]

if n >= 2:
    dp[1][0] = mat[0][0] * mat[0][1] * mat[1][1]
    dp[1][1][0] = mat[0][0]
    dp[1][1][1] = mat[1][1]

    for i in range(2, n):
        dp[i][0] = min(
            dp[i-2][0] + (mat[i-1][0] * mat[i-1][1] * mat[i][1]) + (dp[i-2][1][0] *dp[i-2][1][1] * mat[i][1]),
            dp[i-1][0] + (dp[i-1][1][0] * dp[i-1][1][1] * mat[i][1])
        )
        dp[i][1][0] = mat[0][0]
        dp[i][1][1] = mat[i][1]

print(dp[n-1][0])

