from collections import deque
import sys

N, K = map(int, input().split())

if N >= K:
    print(N - K)
    print(*range(N, K-1, -1))
    sys.exit(0)

parent = [0] * 100_001
costs = [0] * 100_001

queue = deque([N])
while queue:
    cur = queue.popleft()
    if cur == K:
        break 
    for nxt in [cur-1, cur+1, cur*2]:
        if 0<=nxt<=100_000 and not costs[nxt]:
            parent[nxt] = cur
            costs[nxt] = costs[cur] + 1
            queue.append(nxt)

print(costs[cur])
route = []
while K != N:
    route.append(K)
    K = parent[K]
print(N, *route[::-1])
