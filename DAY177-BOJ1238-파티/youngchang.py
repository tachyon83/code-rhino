from collections import defaultdict
from heapq import heappush, heappop


N, M, X = map(int, input().split())

graph = defaultdict(dict)
for _ in range(M):
    i, j, cost = map(int, input().split())
    graph[i][j] = cost

def dij(st, ed):
    memo = [float('inf')] * (N + 1)
    q = [(0, st)]
    while q:
        acc, curr = heappop(q)
        if curr == ed:
            return acc
        for nei in graph[curr]:
            if (tmp := acc + graph[curr][nei]) < memo[nei]:
                memo[nei] = tmp
                heappush(q, (tmp, nei))

answer = 0
for st in range(1, N + 1):
    if st == X:
        continue
    answer = max(answer, dij(st, X) + dij(X, st))

print(answer)