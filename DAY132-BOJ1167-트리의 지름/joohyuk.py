import sys
from collections import deque
si = sys.stdin.readline

v = int(si())
g = [[]for _ in range(v+1)]
for _ in range(v):
    temp = [int(e) for e in si().split()]
    start = temp[0]
    pos = 1
    while pos < len(temp)-1:
        g[start].append([temp[pos], temp[pos+1]])
        g[temp[pos]].append([start, temp[pos+1]])
        pos += 2

vis = [False for _ in range(v+1)]
cost = [0 for _ in range(v+1)]
q = deque()
q.append([1, 0])
vis[1], ns, m = True, 1, 0

while q:
    curr, c = q.popleft()
    for el in g[curr]:
        if not vis[el[0]]:
            cost[el[0]] = c+el[1]
            vis[el[0]] = True
            q.append([el[0], cost[el[0]]])
            if cost[el[0]] > m:
                ns, m = el[0], cost[el[0]]

vis = [False for _ in range(v+1)]
cost = [0 for _ in range(v+1)]
q.append([ns, 0])
vis[ns], m = True, 0

while q:
    curr, c = q.popleft()
    for el in g[curr]:
        if not vis[el[0]]:
            cost[el[0]] = c+el[1]
            vis[el[0]] = True
            q.append([el[0], cost[el[0]]])
            m = max(m, cost[el[0]])

print(m)
