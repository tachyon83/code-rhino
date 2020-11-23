import sys
from collections import deque
si = sys.stdin.readline


def isPossible(i, j, w, h):
    if i == -1 or j == -1 or i == h or j == w:
        return True
    return False


T, dr, dc = int(si()), [0, 1, 0, -1], [-1, 0, 1, 0]
while T:
    T -= 1
    qu, qf, board, t, flag = deque(), deque(), [], 0, False
    w, h = [int(e) for e in si().split()]
    for i in range(h):
        temp = [e for e in si().strip()]
        for j in range(w):
            if temp[j] == '*':
                qf.append([i, j])
            elif temp[j] == '@':
                qu.append([i, j])
        board.append(temp)

    while qu:
        t += 1
        fs = len(qf)
        for _ in range(fs):
            cr, cc = qf.popleft()
            for i in range(4):
                nr, nc = cr+dr[i], cc+dc[i]
                if 0 <= nr < h and 0 <= nc < w and (board[nr][nc] == '.' or board[nr][nc] == '@'):
                    board[nr][nc] = '*'
                    qf.append([nr, nc])
        us = len(qu)
        for _ in range(us):
            cr, cc = qu.popleft()
            for i in range(4):
                nr, nc = cr+dr[i], cc+dc[i]
                if isPossible(nr, nc, w, h):
                    flag, qu = True, deque()
                    break
                if 0 <= nr < h and 0 <= nc < w and board[nr][nc] == '.':
                    board[nr][nc] = '@'
                    qu.append([nr, nc])
            if flag:
                break
    if flag:
        print(t)
    else:
        print('IMPOSSIBLE')
