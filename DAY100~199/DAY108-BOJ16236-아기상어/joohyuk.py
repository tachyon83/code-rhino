import heapq
import sys
from collections import deque
si = sys.stdin.readline

dr, dc = [-1, 0, 0, 1], [0, -1, 1, 0]
n, board, start, sz, T = int(si()), [], False, 2, 0
for i in range(n):
    temp = [int(e) for e in si().split()]
    if not start:
        for j, e in enumerate(temp):
            if e == 9:
                temp[j] = 0
                start = (i, j)
                break
    board.append(temp)

foods = 0
while True:
    visited = [[False for _ in range(n)]for _ in range(n)]
    if foods == sz:
        foods = 0
        sz += 1
    q, t, pq = deque(), 0, []
    q.append(start)
    while q:
        t += 1
        qs = len(q)
        for _ in range(qs):
            curr = q.popleft()
            cr, cc = curr[0], curr[1]
            for i in range(4):
                nr, nc = cr+dr[i], cc+dc[i]
                if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc]:
                    if board[nr][nc] > sz:
                        visited[nr][nc] = True
                    elif board[nr][nc] == sz or not board[nr][nc]:
                        visited[nr][nc] = True
                        q.append((nr, nc))
                    else:
                        heapq.heappush(pq, [t, (nr, nc)])
                        visited[nr][nc] = True
                        q.append((nr, nc))
                        # start = (nr, nc)
                        # T += t
                        # foods += 1
                        # board[nr][nc] = 0
                        # flag = True
                        # break
    if not len(pq):
        print(T)
        break
    temp = heapq.heappop(pq)
    t, start = temp[0], temp[1]
    nr, nc = start[0], start[1]
    board[nr][nc] = 0
    foods += 1
    T += t
