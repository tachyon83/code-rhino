import sys
si = sys.stdin.readline
sys.setrecursionlimit(100000)

n, m = [int(e) for e in si().split()]
g, vis, cnt = [[] for _ in range(n)], [False for _ in range(n)], 0
for i in range(m):
    a, b = [int(e) for e in si().split()]
    g[a].append(b)
    g[b].append(a)


def dfs(p):
    global n, g, vis, cnt
    if cnt >= 5:
        return True
    for nx in g[p]:
        if not vis[nx]:
            cnt += 1
            vis[nx] = True
            dfs(nx)
            if cnt >= 5:
                return True
            cnt -= 1
            vis[nx] = False


for e in range(n):
    cnt, vis = 1, [False for _ in range(n)]
    vis[e] = True
    if dfs(e):
        print(1)
        break

if cnt < 5:
    print(0)
