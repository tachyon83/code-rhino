from sys import stdin
import sys
from heapq import heappush, heappop
sys.setrecursionlimit(1000000)

input = stdin.readline
inf = 9999999999
N, M, X = map(int, input().split())

visited = [inf] * (N+1)
visited_r = [inf] * (N+1)

graph = [[] for _ in range(N+1)]
graph_r = [[] for _ in range(N+1)]

def dijkstra(start, visited, s):
    heap = []
    visited[start] = 0
    heappush(heap, [0, start])
    while heap:
        w, n = heappop(heap)
        if visited[n] < w:
            continue
        for n_n, weight in s[n]:
            n_w = weight + w
            if n_w < visited[n_n]:
                visited[n_n] = n_w
                heappush(heap, [n_w, n_n])

for i in range(M):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph_r[b].append([a, c])

dijkstra(X, visited, graph)
dijkstra(X, visited_r, graph_r)

ans = 0

for i in range(1, N+1):
    ans = max(ans, visited[i], visited_r[i])

print(ans)
