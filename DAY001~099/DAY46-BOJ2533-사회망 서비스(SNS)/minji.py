import sys
sys.setrecursionlimit(10**9)

def dfs(cur):
    ch[cur] = False
    dp[cur][0] = 1
    dp[cur][1] = 0
    for i in tree[cur]:
        if ch[i]:
            dfs(i)
            dp[cur][0] += dp[i][1]
            dp[cur][1] += max(dp[i][0], dp[i][1])
    return n-max(dp[1][0], dp[1][1])

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    tree = [[] for _ in range(n+1)]
    ch = [True for _ in range(n+1)]
    dp = [[0, 0] for _ in range(n + 1)]

    for _ in range(n-1):
        u, v = map(int, sys.stdin.readline().split())
        tree[u].append(v)
        tree[v].append(u)
    print(dfs(1))
