import sys
import copy
import math
from collections import deque
si = sys.stdin.readline

n, m = [int(e) for e in si().split()]
vis, big, board, t = [], math.inf, [], 0
cost = [[[0, 0] for _ in range(m)]for _ in range(n)]
dr, dc = [-1, -2, -2, -1, 1, 2, 2, 1], [-2, -1, 1, 2, 2, 1, -1, -2]
mn = big

for i in range(n):
    row = [e for e in si().strip()]
    for j, e in enumerate(row):
        if e != '.':
            t += 1
            row[j] = int(e)
            cost[i][j][1] = 1
    board.append(row)


def reset():
    global vis
    vis = [[False for _ in range(m)]for _ in range(n)]


def bfs(r, c):
    global big
    reset()
    q, cnt = deque(), -1
    q.append([r, c])
    vis[r][c] = True
    while q:
        qs = len(q)
        cnt += 1
        for _ in range(qs):
            cr, cc = q.popleft()
            for idx in range(8):
                nr, nc = cr+dr[idx], cc+dc[idx]
                if 0 <= nr < n and 0 <= nc < m and not vis[nr][nc]:
                    vis[nr][nc] = True
                    if board[nr][nc] != '.':
                        cost[r][c][0] += cnt//board[nr][nc]+1
                        cost[r][c][1] += 1
                    q.append([nr, nc])


for i in range(n):
    for j in range(m):
        bfs(i, j)
        if cost[i][j][1] == t:
            mn = min(mn, cost[i][j][0])

print(mn if mn != big else -1)
