from sys import stdin

def dfs(y, x, c):
    ret = 1
    d = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    visited[y][x] = 1
    
    z[y][x] = 0
    for i in range(len(d)):
        ny = y + d[i][0]
        nx = x + d[i][1]
        if (nx < 0 or nx >= N or ny < 0 or ny >= M):
            continue
        ret += dfs(ny,nx,c)
    
    return ret


input = stdin.readline

N, M = map(int, input().split())

z = [list(input().strip()) for _ in range(N)]

visited = [[False]*M for _ in range(N)]

for i in range(N):
    for j in range(M):
        if not visited[i][j]:
            k = dfs(i, j, z[i][j])
            if z[i][j] == 'W':
                w += k*k;
            elif z[i][j] == 'B':
                b += k*k;
print(w, b)
