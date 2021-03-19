import sys
from collections import deque
si = sys.stdin.readline

n, k, big = [int(e) for e in si().split()], 10000*100+1
src, dst = [int(e) for e in si().split()]
cost = [[big for _ in range(k+1+1)]for _ in range(n+1)]
g = [[]for _ in range(n+1)]
for edge in edges:
    a, b, c = edge
    g[a].append((b, c))

q = deque()
cost[src][0] = 0
q.append((cost[src][0], src, 0))
while q:
    c, curr, cnt = q.popleft()
    if cost[curr][cnt] < c:
        continue
    for np in g[curr]:
        if cost[np[0]][cnt+1] > cost[curr][cnt]+np[1]:
            cost[np[0]][cnt+1] = cost[curr][cnt]+np[1]
            q.append((cost[np[0]][cnt+1], np[0], cnt+1))

ans=big
for i in range(k+1+1):
    ans=min(ans,cost[dst][i])
print(ans)
