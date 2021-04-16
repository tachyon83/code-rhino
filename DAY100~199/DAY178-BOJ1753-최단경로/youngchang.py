from collections import defaultdict
from heapq import heappush, heappop
from math import inf
import sys
input = sys.stdin.readline


V, E = map(int, input().split())
K = int(input())

graph = [[]for _ in range(V + 1)]
# graph = defaultdict(dict)
for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
    # graph[u][v] = w

memo = [inf] * (V + 1)
memo[K] = 0
q = [(0, K)]
while q:
    dist, curr = heappop(q)
    if dist > memo[curr]:
        continue
    for nei, w in graph[curr]:
    # for nei, w in graph[curr].items():
        if memo[nei] > dist + w:
            memo[nei] = dist + w
            heappush(q, (memo[nei], nei))

for i in range(1, V + 1):
    print(memo[i] if memo[i] != inf else 'INF')