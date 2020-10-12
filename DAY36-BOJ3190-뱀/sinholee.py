from collections import deque
n = int(input())
k = int(input())
mat = [[0] * n for _ in range(n)]

# 사과 등록, 사과 == 1
for _ in range(k):
    y, x = map(int, input().split())
    mat[y-1][x-1] = 1

l = int(input())
moves = deque([[*map(str, input().split())] for _ in range(l)])
    # 우 하 좌 상
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]
cnt = 1
snake = deque([(0, 0, 0)])
mat[0][0] = 2
while True:
    y, x, d = snake[-1]
    ny, nx = y+dy[d], x+dx[d]
    if not(0<=ny<n and 0<=nx<n): break
    if mat[ny][nx] == 2: break
    if len(moves) and int(moves[0][0]) == cnt:
        if moves.popleft()[1] == "D":
            d = (d+1) % 4
        else:
            d = (d+3) % 4
    if mat[ny][nx] == 0:
        y, x, _ = snake.popleft()
        mat[y][x] = 0
    snake.append((ny, nx, d))
    mat[ny][nx] = 2
    cnt += 1

print(cnt)

