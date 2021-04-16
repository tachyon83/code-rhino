import sys
from heapq import heappush, heappop
input = sys.stdin.readline
INF = 1e9
V, E = map(int, input().split())
K = int(input())

graph = [[] for _ in range(V)]

def dijkstra(v, k, g):
    dist = [INF] * v
    dist[k - 1] = 0
    q = []
    heappush(q, [0, k-1])

    while q:
        cost, pos = heappop(q)

        for p, c in g[pos]:
            c += cost
            if c < dist[p]:
                dist[p] = c
                heappush(q, [c, p])

    return dist


for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u-1].append([v-1, w])

for d in dijkstra(V, K, graph):
    print(d if d != INF else "INF")
