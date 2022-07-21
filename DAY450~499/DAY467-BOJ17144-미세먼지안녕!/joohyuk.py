from collections import deque
import sys
si = sys.stdin.readline

dust_q, board, now, cleaner1 = deque(), [], 0, 0
r, c, t = [int(e) for e in si().split()]
for i in range(r):
    row = [[int(e), 0] for e in si().split()]
    for j in range(c):
        if row[j][0] > 0:
            dust_q.append((i, j))
        elif row[j][0] == -1 and not cleaner1:
            cleaner1 = i
            cleaner2 = i+1

    board.append(row)


def spread(r, c):
    global dust_q, board
    dr, dc = [0, 1, 0, -1], [1, 0, -1, 0]
    while dust_q:
        curr = dust_q.popleft()
        cr, cc, acc = curr[0], curr[1], 0
        spr = board[cr][cc][0]//5

        for i in range(4):
            nr, nc = cr+dr[i], cc+dc[i]
            if 0 <= nr < r and 0 <= nc < c and board[nr][nc][0] != -1:
                board[nr][nc][1] += spr
                acc += spr
        board[cr][cc][0] -= acc


def settledown(r, c):
    global board
    for i in range(r):
        for j in range(c):
            if board[i][j][1]:
                board[i][j][0] += board[i][j][1]
                board[i][j][1] = 0


def circulate(cleaner1, cleaner2, r, c):
    global dust_q, board
    for i in range(cleaner1-1, 0, -1):
        board[i][0][0] = board[i-1][0][0]
    for i in range(c-1):
        board[0][i][0] = board[0][i+1][0]
    for i in range(cleaner1):
        board[i][c-1][0] = board[i+1][c-1][0]
    for i in range(c-1, 1, -1):
        board[cleaner1][i][0] = board[cleaner1][i-1][0]
    board[cleaner1][1][0] = 0

    for i in range(cleaner2+1, r-1):
        board[i][0][0] = board[i+1][0][0]
    for i in range(c-1):
        board[r-1][i][0] = board[r-1][i+1][0]
    for i in range(r-1, cleaner2, -1):
        board[i][c-1][0] = board[i-1][c-1][0]
    for i in range(c-1, 1, -1):
        board[cleaner2][i][0] = board[cleaner2][i-1][0]
    board[cleaner2][1][0] = 0

    for i in range(r):
        for j in range(c):
            if board[i][j][0] > 0:
                dust_q.append((i, j))


def totalcount(r, c):
    cnt = 2
    for i in range(r):
        for j in range(c):
            cnt += board[i][j][0]
    return cnt


while now != t:
    now += 1
    spread(r, c)
    settledown(r, c)
    circulate(cleaner1, cleaner2, r, c)
print(totalcount(r, c))
