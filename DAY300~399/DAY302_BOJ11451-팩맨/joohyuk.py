import sys
from collections import deque
si = sys.stdin.readline

t, dr, dc, empty, prv, board = int(
    si()), [0, 1, 0, -1], [1, 0, -1, 0], [0, 0, 0, 0], [], []


def popDir(oc, nc):
    if nc[0]-oc[0] == 1 or nc[0]-oc[0] < -1:
        return 'S'
    if nc[0]-oc[0] == -1 or nc[0]-oc[0] > 1:
        return 'N'
    if nc[1]-oc[1] == 1 or nc[1]-oc[1] < -1:
        return 'E'
    return 'W'


def retrace(r1, c1, r2, c2):
    dir = []
    while prv[r1][c1][r2][c2] != [-1, -1, -1, -1]:
        or1, oc1, or2, oc2 = prv[r1][c1][r2][c2]
        if [r1, c1] != [or1, oc1]:
            dir.append(popDir([or1, oc1], [r1, c1]))
        elif [r2, c2] != [or2, oc2]:
            dir.append(popDir([or2, oc2], [r2, c2]))
        r1, c1, r2, c2 = or1, oc1, or2, oc2
    while dir:
        print(dir.pop(), end='')
    print()


while t:
    t -= 1
    m, n = [int(e) for e in si().split()]
    board, prv, d = [], [[[[[0, 0, 0, 0]
                            for _ in range(n)]for _ in range(m)]for _ in range(n)]for _ in range(m)], 0

    pcoord = []
    for i in range(m):
        row = [e for e in si().strip()]
        for j in range(n):
            if row[j] == 'P':
                pcoord.append(i)
                pcoord.append(j)
        board.append(row)

    prv[pcoord[0]][pcoord[1]][pcoord[2]][pcoord[3]] = [-1, -1, -1, -1]
    q, flag = deque(), False
    q.append(pcoord)
    while q:
        d += 1
        qs = len(q)
        for _ in range(qs):
            curr = q.popleft()
            cr1, cc1 = curr[0], curr[1]
            cr2, cc2 = curr[2], curr[3]

            if cr1 == cr2 and cc1 == cc2:
                flag = True
                break
            for i in range(4):
                nr1, nc1 = cr1+dr[i], cc1+dc[i]
                nr2, nc2 = cr2+dr[i], cc2+dc[i]

                if nr1 < 0:
                    nr1 = m-1
                if nr2 < 0:
                    nr2 = m-1
                if nr1 == m:
                    nr1 = 0
                if nr2 == m:
                    nr2 = 0

                if nc1 < 0:
                    nc1 = n-1
                if nc2 < 0:
                    nc2 = n-1
                if nc1 == n:
                    nc1 = 0
                if nc2 == n:
                    nc2 = 0

                if board[nr1][nc1] != 'G' and board[nr2][nc2] != 'G':
                    if board[nr1][nc1] == 'X':
                        nr1, nc1 = cr1, cc1
                    if board[nr2][nc2] == 'X':
                        nr2, nc2 = cr2, cc2

                    if prv[nr1][nc1][nr2][nc2] == empty:
                        prv[nr1][nc1][nr2][nc2] = [cr1, cc1, cr2, cc2]
                        q.append([nr1, nc1, nr2, nc2])

        if flag:
            break

    if not flag:
        print('IMPOSSIBLE')
    else:
        print(d-1, end=' ')
        retrace(cr1, cc1, cr2, cc2)
