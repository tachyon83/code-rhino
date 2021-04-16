from collections import defaultdict
from heapq import heappop, heappush
from math import inf

N, M = int(input()), int(input())
graph = defaultdict(list)
for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
frm, to = map(int, input().split())

def dijx(graph, start):
    dist = defaultdict(lambda:inf)
    prev = defaultdict(lambda:None)
    dist[start] = 0
    queue = [(dist[start], start)]

    while queue:
        cost, u = heappop(queue)

        for v, c in graph[u]:
            alt = dist[u] + c
            if alt < dist[v]:
                dist[v] = alt
                prev[v] = u
                heappush(queue, (dist[v], v))
    return dist, prev

dist, prev = dijx(graph, frm)
print(dist[to])
