import sys
from collections import deque
si = sys.stdin.readline

n, m = [int(e) for e in si().split()]
g, ins, orders, q = [[]
                     for _ in range(n+1)], [0 for _ in range(n+1)], [], deque()
for _ in range(m):
    a, b = [int(e) for e in si().split()]
    g[a].append(b)
    ins[b] += 1

for i in range(1, n+1):
    if not ins[i]:
        orders.append(i)
        q.append(i)
while q:
    curr = q.popleft()
    for nx in g[curr]:
        ins[nx] -= 1
        if not ins[nx]:
            q.append(nx)
            orders.append(nx)
print(*orders)
