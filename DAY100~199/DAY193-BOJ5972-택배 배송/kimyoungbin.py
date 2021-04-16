import sys
import heapq
n, m = map(int, sys.stdin.readline().split())
g = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    g[a].append((b,c))
    g[b].append((a,c))
dist = [sys.maxsize for _ in range(n + 1)]
dist[1] = 0
q = []
heapq.heappush(q, [1, 0])
while q:
    v, d = heapq.heappop(q)
    if dist[v] >= d:
        for (v_n, d_n) in g[v]:
            if dist[v_n] > dist[v] + d_n:
                dist[v_n] = dist[v] + d_n
                heapq.heappush(q, [v_n, dist[v] + d_n])
print(dist[n])