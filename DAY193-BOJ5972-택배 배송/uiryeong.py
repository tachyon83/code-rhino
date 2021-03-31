import heapq
import sys
INF = sys.maxsize
input = sys.stdin.readline

def dijkstra():
    dist = [INF for _ in range(n+1)]
    dist[1] = 0

    q = []
    heapq.heappush(q, [0, 1])

    while q:
        now_weight, now = heapq.heappop(q)
        for next, weight in graph[now]:
            next_weight = weight + now_weight
            if dist[next] > next_weight:
                heapq.heappush(q, [next_weight, next])
                dist[next] = next_weight

    return dist[-1]

n, m = map(int, input().split())
graph = {i: [] for i in range(n+1)}

for _ in range(m):
    s, e, w = map(int, input().split())
    graph[s].append([e, w])
    graph[e].append([s, w])

print(dijkstra())
