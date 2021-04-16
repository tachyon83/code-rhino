from sys import stdin
import sys
sys.setrecursionlimit(1000000)
input = stdin.readline
N = int(input())

graph = [[] for _ in range(N+1)]
root = [0] * (N+1)

def dfs(x):
    for i in range(len(graph[x])):
        if not root[graph[x][i]]:
            root[graph[x][i]] = x
            dfs(graph[x][i])


for _ in range(N-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

root[1] = 1
dfs(1)
for i in range(2, N+1):
    print(root[i])
