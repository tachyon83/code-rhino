import sys
import heapq
si = sys.stdin.readline

n, m, x = [int(e) for e in si().split()]
big = int(1e2)*int(1e3)+1
g, ig = [[]for _ in range(n+1)], [[]for _ in range(n+1)]
cost1, cost2 = [big for _ in range(n+1)], [big for _ in range(n+1)]
cost1[x], cost2[x] = 0, 0
for _ in range(m):
    a, b, c = [int(e) for e in si().split()]
    g[a].append((b, c))
    ig[b].append((a, c))

pq = []
heapq.heappush(pq, (0, x))
while pq:
    c, curr = heapq.heappop(pq)
    if cost1[curr] < c:
        continue
    for np in g[curr]:
        if cost1[np[0]] > c+np[1]:
            cost1[np[0]] = c+np[1]
            heapq.heappush(pq, (cost1[np[0]], np[0]))
heapq.heappush(pq, (0, x))
while pq:
    c, curr = heapq.heappop(pq)
    if cost2[curr] < c:
        continue
    for np in ig[curr]:
        if cost2[np[0]] > c+np[1]:
            cost2[np[0]] = c+np[1]
            heapq.heappush(pq, (cost2[np[0]], np[0]))

for i in range(1, n+1):
    cost1[i] += cost2[i]

cost1[0] = 0
print(max(cost1))
