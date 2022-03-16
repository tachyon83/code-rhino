import sys
from collections import deque
#sys.stdin = open('input.txt', 'r')

v, e = map(int, input().split())
g = [list() for i in range(v)]
visited = [False] * v

for i in range(0, e):
  v1, v2 = map(int, input().split())
  g[v1-1].append(v2-1)
  g[v2-1].append(v1-1)

cnt = 0
q = deque()
q.append(0)
visited[0] = True

while q:
  curr = q.popleft()
  for i in g[curr]:
    if not visited[i]:
      visited[i] = True
      q.append(i)


for curr in g:
  if len(curr) % 2:
    cnt += 1

if all(visited) and cnt == 0 or cnt == 2:
  print("YES")
else:
  print("NO")

