import sys
import copy
si = sys.stdin.readline

R, C, M = [int(e) for e in si().split()]
v, board, shark, alive, nboard = 0, [[0 for _ in range(C)]for _ in range(R)], [], [], []
dir = [[-1, 0], [1, 0], [0, 1], [0, -1]]

for i in range(M):
    r, c, s, d, z = [int(e) for e in si().split()]
    r -= 1
    c -= 1
    board[r][c] = i+1
    shark.append([s, [r, c], dir[d-1], z])
    alive.append(True)


def catch(c, r):
    for i in range(r):
        if board[i][c] and alive[board[i][c]-1]:
            alive[board[i][c]-1] = False
            return shark[board[i][c]-1][3]
    return 0


def eat(i, j):
    mx, idx = 0, 0
    for sharkIdx in nboard[i][j]:
        if shark[sharkIdx][3] > mx:
            mx = shark[sharkIdx][3]
            idx = sharkIdx
    for sharkIdx in nboard[i][j]:
        if sharkIdx == idx:nboard[i][j] = sharkIdx+1
        else:alive[sharkIdx] = False

def travel(i):
    global R, C
    s, [r, c], [dr, dc], cz = shark[i]
    board[r][c] = 0
    if not s:
        nboard[r][c].add(i)
        return

    if dr:
        if dr > 0:
            if R-1-r < s:
                dr *= -1
                s -= R-1-r
                r = R-1
        else:
            if r < s:
                dr *= -1
                s -= r
                r = 0

        while s > R-1:
            r = 0 if dr < 0 else R-1
            dr *= -1
            s -= R-1

        shark[i][1], shark[i][2] = [r+dr*s, c], [dr, dc]

    else:
        if dc > 0:
            if C-1-c < s:
                dc *= -1
                s -= C-1-c
                c = C-1
        else:
            if c < s:
                dc *= -1
                s -= c
                c = 0

        while s > C-1:
            c = 0 if dc < 0 else C-1
            dc *= -1
            s -= C-1

        shark[i][1], shark[i][2] = [r, c+dc*s], [dr, dc]

    nboard[shark[i][1][0]][shark[i][1][1]].add(i)


def swim(m):
    global nboard, board
    nboard = [[set() for _ in range(C)]for _ in range(R)]
    for i in range(m):
        if alive[i]:travel(i)

    for i in range(R):
        for j in range(C):
            sz = len(nboard[i][j])
            if not sz:nboard[i][j] = 0
            elif sz == 1:nboard[i][j] = nboard[i][j].pop()+1
            else:eat(i, j)
    board = copy.deepcopy(nboard)


for i in range(C):
    v += catch(i, R)
    swim(M)
print(v)
