import sys

dx, dy = (1, 0, -1, 0), (0, 1, 0, -1)
def dfs(x, y):
    if visited[x][y]: return visited[x][y]
    visited[x][y] = 1
    for v in range(4):
        nx, ny = x + dx[v], y + dy[v]
        if 0 <= nx < n and 0 <= ny < n:
            if forest[x][y] < forest[nx][ny]:
                visited[x][y] = max(visited[x][y], dfs(nx, ny) + 1)
    return visited[x][y]
n = int(input())
forest = [list(map(int, input().split())) for i in range(n)]
visited = [[0] * n for i in range(n)]
ret = 0
for i in range(n):
    for j in range(n):
        ret = max(ret, dfs(i, j))
print(ret)
