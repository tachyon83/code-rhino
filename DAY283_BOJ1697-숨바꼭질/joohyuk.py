import sys
from collections import deque
si = sys.stdin.readline

big = int(1e5)
n, k = [int(e) for e in si().split()]
q, t, vis, flag = deque(), 0, [False for _ in range(big+1)], False
q.append(n)
vis[n] = True

while q:
    qs = len(q)
    t += 1
    for _ in range(qs):
        curr = q.popleft()
        if curr == k:
            flag = True
            break
        if curr-1 >= 0 and not vis[curr-1]:
            vis[curr-1] = True
            q.append(curr-1)
        if curr+1 <= big and not vis[curr+1]:
            vis[curr+1] = True
            q.append(curr+1)
        if curr*2 <= big and not vis[curr*2]:
            vis[curr*2] = True
            q.append(curr*2)
    if flag:
        break

print(t-1)
