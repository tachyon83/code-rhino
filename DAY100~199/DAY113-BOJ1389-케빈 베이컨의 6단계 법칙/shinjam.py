import sys
from collections import defaultdict
from heapq import heappush, heappop
from math import inf

input = sys.stdin.readline

N, M = map(int, input().split())
graph = defaultdict(list)
for _ in range(M):
    frm, to = map(int, input().split())
    graph[frm].append(to)
    graph[to].append(frm)

def dijx(graph, start):
    dist = defaultdict(lambda:inf)
    prev = defaultdict(lambda:None)
    dist[start] = 0
    queue = [(dist[start], start)]
    
    while queue:
        cost, u = heappop(queue)
        
        for v in graph[u]:
            alt = dist[u] + 1
            if alt < dist[v]:
                dist[v] = alt
                prev[v] = u
                heappush(queue, (dist[v], v))
    return dist, prev
    
ans = list()
for i in range(1, N+1):
    dist, prev = dijx(graph, i)
    ans.append((sum(dist.values()), i))
ans.sort()
print(ans[0][1])
