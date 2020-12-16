import sys

#sys.stdin = open("input.txt", "r")
N = int(sys.stdin.readline())
K = int(sys.stdin.readline())
board = [[0] * (N + 1) for _ in range(N + 1)]
for _ in range(K):
    x, y = map(int, sys.stdin.readline().split())
    board[x][y] = 1
L = int(sys.stdin.readline())
turn_dir = []
for _ in range(L):
    turn_dir.append(list(sys.stdin.readline().split()))
# 동서남북
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def start():
    x, y = 1, 1
    board[x][y] = 2
    dir = 0
    time = 0
    idx = 0
    snake_trace = [(x, y)]
    while True:
        nx = x + dx[dir]
        ny = y + dy[dir]
        if 1 <= nx <= N and 1 <= ny <= N and board[nx][ny] != 2:
            if board[nx][ny] == 0:
                board[nx][ny] = 2
                snake_trace.append((nx, ny))
                del_x, del_y = snake_trace.pop(0)
                board[del_x][del_y] = 0
            if board[nx][ny] == 1:
                board[nx][ny] = 2
                snake_trace.append((nx, ny))
        else:
            time += 1
            break
        x, y = nx, ny
        time += 1
        if idx<L and time == int(turn_dir[idx][0]):
            dir = turn(dir, turn_dir[idx][1])
            idx += 1
    return time

def turn(direction, char):
    if char == "L":
        direction = (direction - 1) % 4
    else:
        direction = (direction + 1) % 4
    return direction


print(start())
