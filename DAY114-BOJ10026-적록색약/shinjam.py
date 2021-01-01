import sys
from collections import defaultdict, deque

# input = sys.stdin.readline


def r_to_g(board, row, col):
    for i in range(row):
        for j in range(col):
            if board[i][j] == 'G':
                board[i][j] = 'R'
    return board


def bfs(board, start, visited, row, col, color):
    dx, dy = (1, 0, -1, 0), (0, 1, 0, -1)
    queue = deque([start])

    while queue:
        x, y = queue.popleft()

        for v in range(4):
            nx, ny = x + dx[v], y + dy[v]
            if not (0 <= nx < col and 0 <= ny < row):
                continue
            if visited[ny][nx]:
                continue
            if board[ny][nx] != color:
                continue
            visited[ny][nx] = True
            queue.append((nx, ny))


def get_ans(week):
    global BOARD, ROW, COL
    board = r_to_g(BOARD, ROW, COL) if week else BOARD
    ret = defaultdict(int)
    visited = list([0] * COL for _ in range(ROW))
    for i in range(ROW):
        for j in range(COL):
            if not visited[i][j]:
                color = board[i][j]
                bfs(board, (j, i), visited, ROW, COL, color)
                ret[color] += 1
    return sum(ret.values())


ROW = int(input())
BOARD = list(list(input()) for _ in range(ROW))
COL = len(BOARD[0])
no_weak = get_ans(False)
yes_weak = get_ans(True)
print(no_weak, yes_weak)
