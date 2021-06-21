import sys
si = sys.stdin.readline
sys.setrecursionlimit(1000+5)

n = int(si())
dp = [[[-1 for _ in range(1000+2)] for _ in range(2)]for _ in range(n)]
arr = [int(e) for e in si().split()]


def solve(i, prev, mode):
    global n
    if i >= n:
        return 0
    if dp[i][mode][prev] != -1:
        return dp[i][mode][prev]
    if arr[i] > prev:
        if not mode:
            dp[i][mode][prev] = 1+solve(i+1, arr[i], mode)
            dp[i][mode][prev] = max(
                dp[i][mode][prev], 0+solve(i+1, prev, mode))
            dp[i][mode][prev] = max(dp[i][mode][prev], 1+solve(i+1, arr[i], 1))
        dp[i][mode][prev] = max(dp[i][mode][prev], 0+solve(i+1, prev, mode))
    elif arr[i] < prev:
        if not mode:
            dp[i][mode][prev] = max(
                dp[i][mode][prev], 0+solve(i+1, prev, mode))
        dp[i][mode][prev] = max(dp[i][mode][prev], 1+solve(i+1, arr[i], 1))
        dp[i][mode][prev] = max(dp[i][mode][prev], 0+solve(i+1, prev, 1))
    else:
        if not mode:
            dp[i][mode][prev] = max(
                dp[i][mode][prev], 0+solve(i+1, prev, mode))
        dp[i][mode][prev] = max(dp[i][mode][prev], 0+solve(i+1, prev, mode))
    return dp[i][mode][prev]


print(max(solve(0, 0, 0), solve(0, 1000+1, 1)))
