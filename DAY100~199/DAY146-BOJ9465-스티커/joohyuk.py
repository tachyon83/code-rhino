import sys
si = sys.stdin.readline

t = int(si())
while t:
    t -= 1
    n = int(si())
    top = [int(e) for e in si().split()]
    bot = [int(e) for e in si().split()]

    dp = [[0 for _ in range(n)]for _ in range(3)]
    dp[0][0] = top[0]
    dp[1][0] = bot[0]
    dp[2][0] = 0

    for i in range(1, n):
        dp[0][i] = max(top[i]+dp[2][i-1], top[i]+dp[1][i-1])
        dp[1][i] = max(bot[i]+dp[2][i-1], bot[i]+dp[0][i-1])
        dp[2][i] = max(dp[0][i-1], dp[1][i-1], dp[2][i-1])

    print(max(dp[0][n-1], dp[1][n-1], dp[2][n-1]))
