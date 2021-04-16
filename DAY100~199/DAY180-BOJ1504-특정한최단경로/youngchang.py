from heapq import heappush, heappop
import sys
input = sys.stdin.readline


N, E = map(int, input().split())

graph = [[] for _ in range(N + 1)]
for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

v1, v2 = map(int, input().split())

def dij(st, ed):
    memo = [float('inf')] * (N + 1)
    memo[st] = 0
    q = [(0, st)]
    while q:
        acc, curr = heappop(q)
        if curr == ed:
            return acc
        for nei, cost in graph[curr]:
            if memo[nei] > acc + cost:
                memo[nei] = acc + cost
                heappush(q, (acc + cost, nei))
    return float('inf')

ans1 = dij(1, v1) + dij(v1, v2) + dij(v2, N)
ans2 = dij(1, v2) + dij(v2, v1) + dij(v1, N)
answer = min(ans1, ans2)

print(-1 if answer == float('inf') else answer)