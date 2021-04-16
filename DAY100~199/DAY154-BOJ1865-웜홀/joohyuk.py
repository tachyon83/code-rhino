import sys
import math
sys.setrecursionlimit(501)
si = sys.stdin.readline

vis, g, c = [], [], []


def dfs(a):
    global vis, g, c
    for nxp in g[a]:
        if not vis[nxp[0]]:
            vis[nxp[0]] = True
            dfs(nxp[0])


tc = int(si())
while tc:
    tc -= 1
    n, m, w = [int(e) for e in si().split()]
    g = [[]for _ in range(n+1)]
    vis, c = [False for _ in range(n+1)], [math.inf for _ in range(n+1)]

    for _ in range(m):
        s, e, d = [int(e) for e in si().split()]
        g[s].append([e, d])
        g[e].append([s, d])
    for _ in range(w):
        s, e, d = [int(e) for e in si().split()]
        g[s].append([e, -d])

    for i in range(1, n+1):
        if not vis[i]:
            vis[i] = True
            c[i] = 0
            dfs(i)

    ncycle = False
    for i in range(n):
        for j in range(1, n+1):
            for nxp in g[j]:
                nx, d = nxp[0], nxp[1]
                if c[j] != math.inf and c[nx] > c[j]+d:
                    c[nx] = c[j]+d
                    if i == n-1:
                        ncycle = True
    if ncycle:
        print('YES')
    else:
        print('NO')
