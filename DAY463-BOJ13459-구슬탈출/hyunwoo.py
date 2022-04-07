import sys
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(rx, ry, bx, by):
    q = deque()
    q.append((rx, ry, bx, by))
    visited = [(rx, ry, bx, by)]
    count = 0

    while q:
        for _ in range(len(q)):
            rx, ry, bx, by = q.popleft()
            if count > 10:
                return False
            if grid[rx][ry] == 'O':
                return True

            for k in range(4):

                nrx, nry = rx, ry
                while True:
                    nrx += dx[k]
                    nry += dy[k]
                    if grid[nrx][nry] == '#':
                        nrx -= dx[k]
                        nry -= dy[k]
                        break
                    if grid[nrx][nry] == 'O':
                        break

                nbx, nby = bx, by
                while True:
                    nbx += dx[k]
                    nby += dy[k]
                    if grid[nbx][nby] == '#':
                        nbx -= dx[k]
                        nby -= dy[k]
                        break
                    if grid[nbx][nby] == 'O':
                        break

                if grid[nbx][nby] == 'O':
                    continue

                if nrx == nbx and nry == nby:
                    if abs(nrx - rx) + abs(nry - ry) > abs(nbx - bx) + abs(nby - by):
                        nrx -= dx[k]
                        nry -= dy[k]
                    else:
                        nbx -= dx[k]
                        nby -= dy[k]
                if (nrx, nry, nbx, nby) not in visited:
                    q.append((nrx, nry, nbx, nby))
                    visited.append((nrx, nry, nbx, nby))
        count += 1
    return False

n, m = map(int, sys.stdin.readline().split())
grid = [list(sys.stdin.readline().rstrip()) for _ in range(n)]

rx, ry, bx, by = 0, 0, 0, 0

for i in range(n):
    for j in range(m):
        if grid[i][j] == 'R':
            rx, ry = i, j
        elif grid[i][j] == 'B':
            bx, by = i, j

if bfs(rx, ry, bx, by):
    print(1)
else:
    print(0)
