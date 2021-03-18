import sys
import heapq


def dijkstra(start):
    q = []
    res = [sys.maxsize for _ in range(n+1)]
    res[start] = 0
    heapq.heappush(q, [start, 0])
    while q:
        t, d = heapq.heappop(q)
        if d > res[t]:
            continue
        for i, di in g[t]:
            di += d
            if di < res[i]:
                res[i] = di
                heapq.heappush(q, [i, di])

    return res


n, e = map(int, sys.stdin.readline().split())
g = [[] for _ in range(n+1)]
for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    g[a].append([b,c])
    g[b].append([a,c])
v1, v2 = map(int,sys.stdin.readline().split())

d1 = dijkstra(1)
d2 = dijkstra(v1)
res1 = d1[v1] + d2[v2] + dijkstra(v2)[n]
res2 = d1[v2] + d2[v2] + d2[n]

if res2 >= sys.maxsize and res1 >= sys.maxsize:
    print(-1)
else:
    print(min(res1, res2))