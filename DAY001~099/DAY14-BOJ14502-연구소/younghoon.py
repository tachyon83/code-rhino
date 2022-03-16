# 7 7
# 2 0 0 0 1 1 0
# 0 0 1 0 1 2 0
# 0 1 1 0 1 0 0
# 0 1 0 0 0 0 0
# 0 0 0 0 0 1 1
# 0 1 0 0 0 0 0
# 0 1 0 0 0 0 0
import sys
# 세로, 가로
N, M = map(int, sys.stdin.readline().split())
temp = list([0] * M for _ in range(N))
board = []
for _ in range(N):
    board.append(list(map(int, input().split())))

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 원본 복사
def copy(board, temp):
    for i in range(N):
        for j in range(M):
            temp[i][j] = board[i][j]

# 바이러스 퍼트리기
def spread(x,y):
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if 0<=nx<N and 0<=ny<M and temp[nx][ny] == 0:
            temp[nx][ny] = 2
            spread(nx, ny)

def safe_area():
    count = 0
    for i in range(N):
        for j in range(M):
            if temp[i][j] == 0:
                count += 1
    return count
                
result = 0
def dfs(count):
    global result
    if count == 3:
        copy(board, temp)    
        for i in range(N):
            for j in range(M):
                if temp[i][j] == 2:
                    spread(i,j)
        result = max(result, safe_area())
        return
    for i in range(N):
        for j in range(M):
            if board[i][j] == 0:
                board[i][j] = 1
                dfs(count + 1)
                board[i][j] = 0

dfs(0)
print(result)

