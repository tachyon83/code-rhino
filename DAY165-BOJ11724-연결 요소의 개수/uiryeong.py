from sys import stdin
import sys
sys.setrecursionlimit(10000)
input = stdin.readline
N, M = map(int, input().split())
visited = [False] * (N+1)
graph = [[] for _ in range(N+1)]

for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

def dfs(now):
    visited[now] = True

    for i in graph[now]:
        if visited[i] is False:
            dfs(i)

ret = 0

for i in range(1, N+1):
    if visited[i] == False:
        dfs(i)
        ret += 1
print(ret)
