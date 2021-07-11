import sys
from collections import deque
si = sys.stdin.readline

n, m = [int(e) for e in si().split()]
board, dr, dc, cn = [], [0, 1, 0, -1], [-1, 0, 1, 0], 1
vis = [[False for _ in range(m)]for _ in range(n)]

for _ in range(n):
    row = [int(e) for e in si().split()]
    board.append(row)


def dfs(i, j, cn):
    board[i][j] = cn
    global n, m
    for idx in range(4):
        ni, nj = i+dr[idx], j+dc[idx]
        if 0 <= ni < n and 0 <= nj < m and board[ni][nj] and not vis[ni][nj]:
            vis[ni][nj] = True
            dfs(ni, nj, cn)


for i in range(n):
    for j in range(m):
        if board[i][j] and not vis[i][j]:
            vis[i][j] = True
            dfs(i, j, cn)
            cn += 1

big = 101
ct = [[big for _ in range(cn)]for _ in range(cn)]
root, cost = [i for i in range(cn)], 0


def find(a):
    if root[a] == a:
        return a
    root[a] = find(root[a])
    return root[a]


def union(a, b):
    a, b = find(a), find(b)
    root[a] = b


vis = [[False for _ in range(m)]for _ in range(n)]


def check(i, j):
    global n, m
    for idx in range(4):
        ni, nj, b, cn = i+dr[idx], j+dc[idx], 0, 0
        while 0 <= ni < n and 0 <= nj < m:
            if not board[ni][nj]:
                b += 1
                ni, nj = ni+dr[idx], nj+dc[idx]
            else:
                if board[i][j] != board[ni][nj]:
                    cn = board[ni][nj]
                break

        if b > 1 and cn:
            ct[board[i][j]][cn] = min(ct[board[i][j]][cn], b)


for i in range(n):
    for j in range(m):
        if board[i][j] and not vis[i][j]:
            vis[i][j] = True
            check(i, j)

bridges = []
for i in range(1, cn):
    for j in range(i+1, cn):
        if ct[i][j] < big:
            bridges.append([ct[i][j], [i, j]])
bridges.sort()

for bridge in bridges:
    v, [s, e] = bridge
    if find(s) != find(e):
        union(s, e)
        cost += v

flag = False if cn > 1 else True
p = find(1)
for i in range(1, cn):
    if find(i) != p:
        flag = True
print(-1 if flag else cost)
