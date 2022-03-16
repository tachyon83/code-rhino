from collections import deque

def bfs(y,x):
    q = deque()
    q.append((y,x))
    while q:
        now = q.popleft()
        for l in range(4):
            ny = now[0] + dy[l]
            nx = now[1] + dx[l]
            if 0 <= nx < w and 0 <= ny < h and matrix[ny][nx] == 1:
                matrix[ny][nx] = 0
                q.append((ny,nx))

dx = [0,1,0,-1]
dy = [-1,0,1,0]
T = int(input())
for _ in range(T):
    w, h, k = map(int, input().split())
    matrix = [[0]*w for _ in range(h)]
    result = 0
    for _ in range(k):
        x, y = map(int, input().split())
        matrix[y][x] = 1
    for i in range(h):
        for j in range(w):
            if matrix[i][j] == 1:
                matrix[i][j] = 0
                bfs(i,j)
                result += 1
    print(result)
