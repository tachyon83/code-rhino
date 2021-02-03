import sys
from collections import deque
si = sys.stdin.readline

n = int(si())
g = [[]for _ in range(n+1)]
routes = [[-1 for _ in range(n+1)]for _ in range(n+1)]

for i in range(n):
    a, b = [int(e) for e in si().split()]
    g[a].append(b)
    g[b].append(a)
    routes[a][b], routes[b][a] = i, i


def check(a):
    global g, routes
    routesVis = [False for _ in range(n)]
    vis = [False for _ in range(n+1)]
    vis[a] = True
    q = deque()
    q.append(a)

    while q:
        curr = q.popleft()
        for nx in g[curr]:
            if routesVis[routes[curr][nx]]:
                continue
            if nx == a:
                return True
            if not vis[nx]:
                vis[nx] = True
                routesVis[routes[curr][nx]] = True
                q.append(nx)
    return False


isCircle = [False for _ in range(n+1)]
for i in range(1, n+1):
    if check(i):
        isCircle[i] = True

print(*isCircle)
# ans = []
# for i in range(1, n+1):
#     if isCircle[i]:
#         ans.append(0)
#         continue

#     t, q, vis = 0, deque(), [False for _ in range(n+1)]
#     vis[i] = True
#     q.append(i)
#     while q:
#         qs = len(q)
#         t += 1
#         for _ in range(qs):
#             curr = q.popleft()
#             for nx in g[curr]:
#                 if isCircle[nx]:
#                     ans.append(t)
#                     flag = True
#                     break
#                 if not vis[nx]:
#                     vis[nx] = True
#                     q.append(nx)
