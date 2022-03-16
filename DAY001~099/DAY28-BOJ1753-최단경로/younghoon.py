import sys
import heapq
#sys.stdin = open("input.txt", "r")
inpu = sys.stdin.readline
INF = sys.maxsize
V, E = map(int, inpu().split())
K = int(input())
G = [[] for i in range(V + 1)]

for _ in range(E):
    u, v, w = map(int, inpu().split())
    G[u].append([v, w])

def shortest_path(v, start, g):
    dist = [INF] * (V + 1)
    dist[start] = 0
    q = []
    heapq.heappush(q, [0, start])
    while q:
        weight, edge = heapq.heappop(q)
        for dest, cost in g[edge]:
            cost += weight
            if cost < dist[dest]:
                dist[dest] = cost
                heapq.heappush(q, [cost, dest])
    return dist[1:]

for w in shortest_path(V, K, G):
    print(w if w != INF else "INF")



