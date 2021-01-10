from collections import defaultdict 
import sys

input = sys.stdin.readline

def dfs(v, depth=0):
    global ans, graph, visited
    visited[v] = True
    if depth >= 4:
        ans = 1
        return
    for nxt in graph[v]:
        if not visited[nxt]:
            dfs(nxt, depth+1)
            visited[nxt] = False

N, M = map(int, input().split())
graph = defaultdict(list)

for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [False] * N
ans = 0
for i in range(N):
    dfs(i)
    visited[i] = False
    if ans: break
print(ans)
