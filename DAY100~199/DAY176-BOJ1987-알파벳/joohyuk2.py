import sys
si = sys.stdin.readline

dr, dc, m = [0, 1, 0, -1], [1, 0, -1, 0], 0
r, c = [int(e) for e in si().split()]
board = []
for _ in range(r):
    board.append(si()[:-1])


def dfs(i, j, s):
    global m, dr, dc, r, c
    m = max(m, len(s))
    for idx in range(4):
        ni, nj = i+dr[idx], j+dc[idx]
        if 0 <= ni < r and 0 <= nj < c and board[ni][nj] not in s:
            dfs(ni, nj, s+board[ni][nj])


dfs(0, 0, board[0][0])
print(m)
