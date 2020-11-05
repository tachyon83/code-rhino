from collections import deque
import sys

MAX = 100_000

N, K = map(int, input().split())

if N >= K:
    print(N - K)
    print(*range(N, K-1, -1))
    sys.exit(0)

parent = [p for p in range(MAX+1)]

queue = deque([[N, 0]])
while queue:
    cur, cost = queue.popleft()
    if cur == K:
        break 
    for nxt in [cur-1, cur+1, cur*2]:
        if 0<=nxt<=MAX and parent[nxt]==nxt:
            parent[nxt] = cur
            queue.append([nxt, cost+1])

print(cost)
route = []
while K != N:
    route.append(K)
    K = parent[K]
print(N, *route[::-1])
