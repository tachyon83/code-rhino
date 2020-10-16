import sys
from collections import deque
si = sys.stdin.readline

n = int(si())
ic, graph = [0 for _ in range(n+1)], [[]for _ in range(n+1)]
cost, q, acc = [0 for _ in range(n+1)], deque(), [0 for _ in range(n+1)]
for i in range(1, n+1):
    given = [int(e) for e in si().split()]
    cost[i] = given[0]
    if not given[1]:
        continue
    for j in range(given[1]):
        graph[given[2+j]].append(i)
        ic[i] += 1
for i in range(1, 1+n):
    if not ic[i]:
        q.append(i)
while q:
    curr = q.popleft()
    cost[curr] += acc[curr]
    for nx in graph[curr]:
        acc[nx] = max(acc[nx], cost[curr])
        ic[nx] -= 1
        if not ic[nx]:
            q.append(nx)
print(max(cost))
