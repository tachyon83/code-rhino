import sys
import heapq
si = sys.stdin.readline

v, e = [int(e) for e in si().split()]
s, big = int(si()), int(2e4)*10+1
cost = [big for _ in range(v+1)]
cost[s] = 0

g = [[]for _ in range(v+1)]
for _ in range(e):
    a, b, w = [int(e) for e in si().split()]
    g[a].append((b, w))

pq = []
heapq.heappush(pq, (0, s))
while pq:
    c, curr = heapq.heappop(pq)
    if c > cost[curr]:
        continue
    for np in g[curr]:
        if cost[np[0]] > c+np[1]:
            cost[np[0]] = c+np[1]
            heapq.heappush(pq, (cost[np[0]], np[0]))

for e in range(1, v+1):
    print(cost[e] if cost[e] != big else 'INF')
