import sys
sys.setrecursionlimit(100000)

N, M = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N+1)]
visited = [False] * N
result = 0

for _ in range(M):
    x,y = map(int, sys.stdin.readline().split())
    graph[x].append(y)
    graph[y].append(x)

def dfs(x, count):
    global result
    visited[x] = True
    if count == 5:
        result = 1
        return
    
    for i in graph[x]:
        if not visited[i]:
            dfs(i, count + 1)
            visited[i] = False
            if result == 1:
                return

for i in range(N):
    if not visited[i]:
        dfs(i,1)
        visited[i] = False
        if result == 1:
            break

print(result)
