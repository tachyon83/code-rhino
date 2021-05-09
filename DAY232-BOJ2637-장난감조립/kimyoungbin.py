import sys
from collections import deque

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

graph = [[] for _ in range(n + 1)]
indegree = [0 for _ in range(n + 1)]
cnt = [0 for _ in range(n + 1)]

for _ in range(m):
    x, y, z = map(int, sys.stdin.readline().split())
    graph[x].append([y, z])
    indegree[y] += 1

q = deque()
q.append(n)
cnt[n] = 1
ans = []
while len(q) != 0:
    cur = q.popleft()
    if len(graph[cur]) == 0:
        ans.append(cur)
    for g in graph[cur]:
        next = g[0]
        cost = g[1]
        cnt[next] += cnt[cur] * cost
        indegree[next] -= 1
        if indegree[next] == 0:
            q.append(next)
ans.sort()
for a in ans:
    print('{} {}'.format(a, cnt[a]))

