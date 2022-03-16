import sys
si = sys.stdin.readline

cnt = int(si())
opens = [int(e) for e in si().split()]
t, arr = int(si()), []
while t:
    t -= 1
    arr.append(int(si()))

dp = [[[-1 for _ in range(cnt+1)]for _ in range(cnt+1)]for _ in range(cnt+1)]


def dfs(i, l, r):
    global cnt
    if dp[i][l][r] != -1:
        return dp[i][l][r]
    if i == len(arr):
        return 0
    c1 = abs(l-arr[i])+dfs(i+1, arr[i], r)
    c2 = abs(r-arr[i])+dfs(i+1, l, arr[i])
    dp[i][l][r] = min(c1, c2)
    return dp[i][l][r]


print(dfs(0, opens[0], opens[1]))
