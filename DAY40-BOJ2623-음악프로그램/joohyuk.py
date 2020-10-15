import sys
from collections import deque
si = sys.stdin.readline
n, m = [int(e) for e in si().split()]
graph, ic, q, o = [[]
                   for _ in range(n+1)], [0 for _ in range(n+1)], deque(), []
while m:
    m -= 1
    kl = [int(e) for e in si().split()]
    k, l = kl[0], kl[1:]
    for i in range(1, k):
        graph[l[i-1]].append(l[i])
        ic[l[i]] += 1
for i in range(1, n+1):
    if not ic[i]:
        q.append(i)
while q:
    curr = q.popleft()
    o.append(curr)
    for nx in graph[curr]:
        ic[nx] -= 1
        if not ic[nx]:
            q.append(nx)
if len(o) != n:
    print(0)
else:
    for e in o:
        print(e)
