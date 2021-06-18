import sys
si = sys.stdin.readline

dp = [[[-1 for _ in range(60+1)]for _ in range(60+1)]for _ in range(60+1)]


def solve(a, b, c):
    if a <= 0 and b <= 0 and c <= 0:return 0
    if a < 0:a = 0
    if b < 0:b = 0
    if c < 0:c = 0

    if dp[a][b][c] != -1:return dp[a][b][c]

    dp[a][b][c] = 1+solve(a-9, b-3, c-1)
    dp[a][b][c] = min(dp[a][b][c], 1+solve(a-9, b-1, c-3))
    dp[a][b][c] = min(dp[a][b][c], 1+solve(a-3, b-1, c-9))
    dp[a][b][c] = min(dp[a][b][c], 1+solve(a-3, b-9, c-1))
    dp[a][b][c] = min(dp[a][b][c], 1+solve(a-1, b-3, c-9))
    dp[a][b][c] = min(dp[a][b][c], 1+solve(a-1, b-9, c-3))
    return dp[a][b][c]


n = int(si())
given = [int(e) for e in si().split()]
while len(given) < 3:given.append(0)
print(solve(*given))
