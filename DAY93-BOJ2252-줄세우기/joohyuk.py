import sys
from collections import deque
si = sys.stdin.readline
sys.setrecursionlimit(100000)

n, m = [int(e) for e in si().split()]
ins, ans, graph = [0 for _ in range(n+1)], [], [[]for _ in range(n+1)]
while m:
    m -= 1
    a, b = [int(e) for e in si().split()]
    graph[a].append(b)
    ins[b] += 1
q = deque()
for i in range(1, n+1):
    if not ins[i]:
        q.append(i)
while q:
    curr = q.popleft()
    ans.append(curr)
    for e in graph[curr]:
        ins[e] -= 1
        if not ins[e]:
            q.append(e)
print(*ans)
