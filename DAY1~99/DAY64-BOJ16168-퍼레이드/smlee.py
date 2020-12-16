from collections import deque

v, e = map(int, input().split())
graph = [list() for i in range(v)]
visited = [False] * v

for i in range(0, e):
  v1, v2 = map(int, input().split())
  graph[v1-1].append(v2-1)
  graph[v2-1].append(v1-1)

cnt = 0
q = deque()
q.append(0)
visited[0] = True

while q:
  x = q.popleft()
  for i in graph[x]:
    if not visited[i] :
      visited[i] = True
      q.append(i)

for g in graph:
  if len(g) % 2:
    cnt += 1

if all(visited) and cnt == 0 or cnt == 2 :
  print("YES")
else:
  print("NO")
