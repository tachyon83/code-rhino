import sys
si = sys.stdin.readline

gr, board, zs = [set() for _ in range(9)], [], []
rs, cs = [set() for _ in range(9)], [set() for _ in range(9)]


def form():
    global gr, board, given
    for i in range(9):
        for j in range(9):
            rs[i].add(board[i][j])
            cs[j].add(board[i][j])
            gr[findGrNum(i, j)].add(board[i][j])


def printer():
    global board
    for k in range(9):
        print(*board[k])


def findGrNum(i, j):
    return i//3*3+j//3


def find(e):
    global board, gr, zs
    if e >= len(zs):
        return True
    i, j = zs[e]
    grn = findGrNum(i, j)
    for k in range(1, 9+1):
        if k not in rs[i] and k not in cs[j] and k not in gr[grn]:
            board[i][j] = k
            rs[i].add(k)
            cs[j].add(k)
            gr[grn].add(k)
            if find(e+1):
                return True
            else:
                rs[i].remove(k)
                cs[j].remove(k)
                gr[grn].remove(k)
    return False


for _ in range(9):
    board.append([int(e) for e in si().split()])

form()
for i in range(9):
    for j in range(9):
        if not board[i][j]:
            zs.append((i, j))


if zs:
    find(0)
printer()
