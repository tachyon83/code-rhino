from collections import deque
import sys

MAX = 100_000

N, K = map(int, input().split())

if N >= K:
    print(N - K)
    print(*range(N, K-1, -1))
    sys.exit(0)

parent = [p for p in range(MAX+1)]
costs = [MAX for _ in range(MAX+1)]

queue = deque([[N, 0]])
while queue:
    cur, cost = queue.popleft()
    
    if cur == K:
        break
        
    for nxt in [cur-1, cur+1, cur*2]:
        if nxt < 0 or nxt > MAX:
            continue
        if costs[nxt] != MAX:
            continue
        if costs[nxt] > cost+1:
            costs[nxt] = cost+1
            parent[nxt] = cur
            queue.append([nxt, cost+1])

print(costs[K])
route = []
while K != N:
    route.append(K)
    K = parent[K]
print(N, *route[::-1])
