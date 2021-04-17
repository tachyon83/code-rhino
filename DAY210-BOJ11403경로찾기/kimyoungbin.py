import sys

def dfs(start):
    for i in range(n):
        if visit[i] == 0 and g[start][i]:
            visit[i] = 1
            dfs(i)

n = int(sys.stdin.readline())
visit = [0 for _ in range(n)]
g = []
for _ in range(n):
    g.append(list(map(int, sys.stdin.readline().split())))
for i in range(n):
    dfs(i)
    print(' '.join(map(str, visit)))
    visit = [0 for _ in range(n)]