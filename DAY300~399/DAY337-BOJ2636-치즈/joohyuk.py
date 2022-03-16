import sys
from collections import deque
si = sys.stdin.readline

root, dr, dc, ambient = [], [0, 1, 0, -1], [1, 0, -1, 0], [0, 0]


def union(a, b):
    a, b = find(a), find(b)
    if b == ambient:
        root[a[0]][a[1]] = b
        return
    root[b[0]][b[1]] = a


def find(a):
    if root[a[0]][a[1]] == [-1, -1]:return [a[0], a[1]]
    root[a[0]][a[1]] = find(root[a[0]][a[1]])
    return root[a[0]][a[1]]


def isAmbient(a):
    if root[a[0]][a[1]] == ambient:return True
    return False


board, q = [], deque()
n, m = [int(e) for e in si().split()]
root = [[[-1, -1] for _ in range(m)]for _ in range(n)]
for _ in range(n):board.append([int(e) for e in si().split()])

visited = [[False for _ in range(m)]for _ in range(n)]
visited[0][0] = True
q.append([0, 0])
while q:
    curr = q.popleft()
    for i in range(4):
        nr, nc = curr[0]+dr[i], curr[1]+dc[i]
        if 0 <= nr < n and 0 <= nc < m and not visited[nr][nc] and not board[nr][nc]:
            union(curr, [nr, nc])
            visited[nr][nc] = True
            q.append([nr, nc])

meltset = set()
for i in range(n):
    for j in range(m):
        if board[i][j]:
            for k in range(4):
                nr, nc = i+dr[k], j+dc[k]
                if 0 <= nr < n and 0 <= nc < m and not board[nr][nc]:
                    if isAmbient([nr, nc]):
                        q.append([i, j])
                        meltset.add((i, j))
                        root[i][j] = ambient
                        break

t, leftover, nq = 0, 0, deque()
while q:
    qs = len(q)
    leftover = qs
    t += 1
    for _ in range(qs):
        curr = q.popleft()
        board[curr[0]][curr[1]] = 0
        for i in range(4):
            nr, nc = curr[0]+dr[i], curr[1]+dc[i]
            if 0 <= nr < n and 0 <= nc < m:
                if board[nr][nc] and (nr, nc) not in meltset:
                    q.append([nr, nc])
                    meltset.add((nr, nc))
                    root[nr][nc] = ambient
                elif not board[nr][nc] and find([nr, nc]) != ambient:
                    root[nr][nc] = ambient
                    nq.append([nr, nc])
                    while nq:
                        ncurr = nq.popleft()
                        for j in range(4):
                            nqr, nqc = ncurr[0]+dr[j], ncurr[1]+dc[j]
                            if 0 <= nqr < n and 0 <= nqc < m:
                                if board[nqr][nqc] and (nqr, nqc) not in meltset:
                                    q.append([nqr, nqc])
                                    meltset.add((nqr, nqc))
                                    root[nqr][nqc] = ambient
                                elif not board[nqr][nqc] and find([nqr, nqc]) != ambient:
                                    root[nqr][nqc] = ambient
                                    nq.append([nqr, nqc])
print(t)
print(leftover)
