import sys
from collections import deque

dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def move(y, x, dy, dx):
    cnt = 0
    while maps[y+dy][x+dx] != '#' and maps[y][x] != 'O':
        y, x = y+dy, x +dx
        cnt += 1
    return y, x, cnt

def bfs(ry, rx, by, bx, cnt):
    q = deque()
    q.append((ry, rx, by, bx, cnt))
    visited = [(ry, rx, by, bx)]
    while q:
        sry, srx, sby, sbx, scnt = q.popleft()
        if scnt > 10:
            return -1
        for dy, dx in dir:
            nry, nrx, rcnt = move(sry, srx, dy, dx)
            nby, nbx, bcnt = move(sby, sbx, dy, dx)
            if maps[nby][nbx] == 'O':
                continue
            if maps[nry][nrx] == 'O':
                return scnt
            if nry == nby and nrx == nbx:
                if rcnt > bcnt:
                    nry, nrx = nry-dy, nrx-dx
                else:
                    nby, nbx = nby - dy, nbx - dx
            if (nry, nrx, nby, nbx) not in visited:
                visited.append((nry, nrx, nby, nbx))
                q.append((nry, nrx, nby, nbx, scnt+1))
    return -1

if __name__ == "__main__":
    n, m = list(map(int, sys.stdin.readline().split()))
    maps = [list(map(str, sys.stdin.readline().strip())) for _ in range(n)]

    for y in range(n):
        for x in range(m):
            if maps[y][x] == 'R':
                ry, rx = y, x
            elif maps[y][x] == 'B':
                by, bx = y, x

    print(bfs(ry, rx, by, bx, 1))
