from collections import deque
import sys
#sys.stdin = open("input.txt", "r")
M, N = map(int, sys.stdin.readline().split())
# 1익은토마토 0 익지않은 -1 토마토 없는
tomato_box = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
# 동서남북
dx = [1,-1,0,0]
dy = [0,0,1,-1]

matured = deque()
for i in range(N):
    for j in range(M):
        if tomato_box[i][j] == 1:
            matured.append([i,j])

def bfs():
    global matured
    days = 0
    while matured:
        days += 1
        for _ in range(len(matured)):
            x,y = matured.popleft()
            for i in range(4):
                nx = x+dx[i]
                ny = y+dy[i]
                if 0 <= nx < N and 0 <= ny < M and tomato_box[nx][ny] == 0:
                    tomato_box[nx][ny] = tomato_box[x][y] + 1
                    matured.append([nx,ny])
    for i in range(N):
        for j in range(M):
            if tomato_box[i][j] == 0:
                return -1
    return days-1

print(bfs())
