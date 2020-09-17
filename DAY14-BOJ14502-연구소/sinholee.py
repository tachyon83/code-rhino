n,m = map(int, input().split())


mat = [list(map(int, input().split())) for _ in range(n)]

empty = []
virus = []
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def bfs(d_mat, virus, safe_area):
    q = []
    for y, x in virus:
        d_mat[y][x] = 2
        q.append((y, x))
    while q:
        y, x = q.pop(0)
        for d in range(4):
            ny, nx = y+dy[d], x+dx[d]
            if not(0<=ny<n and 0<=nx<m):
                continue
            if d_mat[ny][nx]:
                continue
            d_mat[ny][nx] = 2
            safe_area -= 1
            q.append((ny, nx)) 
    return safe_area


safe_area = 0
res = 0
for i in range(n):
    for j in range(m):
        if mat[i][j] == 0:
            empty.append((i, j))
            safe_area += 1
        if mat[i][j] == 2:
            virus.append((i, j))

for i in range(len(empty)-2):
    for j in range(i+1, len(empty)-1):
        for k in range(j+1, len(empty)):
            copyed_mat = [arr[:] for arr in mat]
            copyed_mat[empty[i][0]][empty[i][1]] = 1
            copyed_mat[empty[j][0]][empty[j][1]] = 1
            copyed_mat[empty[k][0]][empty[k][1]] = 1
        
            res = max(res, bfs(copyed_mat, virus, safe_area-3))
                
print(res)
