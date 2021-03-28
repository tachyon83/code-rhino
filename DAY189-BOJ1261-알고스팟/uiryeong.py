import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

m, n = map(int,input().rstrip().rsplit())
matrix = []

for _ in range(n):
    row = input().rstrip()
    matrix.append(row)

dist = [[-1] *(m+1) for _ in range(n+1)]
dist[0][0]=0

q = deque()
q.append((0,0))


while q:
    p = q.popleft()
    cur_x, cur_y = p[0], p[1]

    for k in range(4):
        nx = dx[k] + cur_x
        ny = dy[k] + cur_y
        if (0 <= nx < n and 0 <= ny < m):
            if dist[nx][ny]!=-1:
                continue

            if matrix[nx][ny] == '1':
                q.append((nx,ny))
                dist[nx][ny] = dist[cur_x][cur_y] + 1 
            else:
                q.appendleft((nx,ny))
                dist[nx][ny] = dist[cur_x][cur_y] 

print(dist[n-1][m-1])
