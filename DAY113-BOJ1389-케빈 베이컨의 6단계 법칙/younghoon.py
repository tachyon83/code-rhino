from collections import defaultdict
from collections import deque
import sys

graph = defaultdict(list) 
N, M = map(int, sys.stdin.readline().split())

for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    
    graph[a].append(b) 
    graph[b].append(a) 


depth = [0] * (N + 1)

def bfs(v):
    count = 0
    q = deque([[v, count]])
    while q:
        value = q.popleft()
        v = value[0]
        count = value[1]
        if not visited[v]:
            visited[v] = True
            depth[v] += count
            count += 1
            for e in graph[v]:
                q.append([e, count])
                
for i in range(1, N + 1):
    visited = [False] * (N + 1)
    bfs(i)

print(depth.index(min(depth[1:]))) 
