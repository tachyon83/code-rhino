import sys
import copy
from itertools import combinations as cb
from collections import deque
si = sys.stdin.readline

n, m = [int(e) for e in si().split()]
iboard, q, v, carr = [], deque(), [], []
dr, dc = [0, 1, 0, -1], [1, 0, -1, 0]


def bfs(n, m):
    while q:
        cr, cc = q.popleft()
        for i in range(4):
            nr, nc = cr+dr[i], cc+dc[i]
            if 0 <= nr < n and 0 <= nc < m and not board[nr][nc]:
                board[nr][nc] = 2
                q.append([nr, nc])


def count(n, m):
    cnt = 0
    for i in range(n):
        for j in range(m):
            if not board[i][j]:
                cnt += 1
    return cnt


for i in range(n):
    row = [int(e) for e in si().split()]
    for j, e in enumerate(row):
        if not e:
            carr.append(i*m+j)
        elif e == 2:
            v.append([i, j])
    iboard.append(row)

c, mx = cb(carr, 3), 0
for ea in c:
    board = copy.deepcopy(iboard)
    for e in ea:
        board[e//m][e % m] = 1
    for e in v:
        q.append(e)
    bfs(n, m)
    mx = max(mx, count(n, m))

print(mx)
