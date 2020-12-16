import sys
from collections import deque
si = sys.stdin.readline

dr, dc = [0, 1, 0, -1], [1, 0, -1, 0]
t = int(si())
while t:
    t -= 1
    m, n, k = [int(e) for e in si().split()]
    board = [[0 for _ in range(n)]for _ in range(m)]
    visited = [[False for _ in range(n)]for _ in range(m)]
    while k:
        k -= 1
        x, y = [int(e) for e in si().split()]
        board[x][y] = 1

    def expand(i, j, m, n):
        global dr, dc, board, visited
        q = deque()
        q.append((i, j))
        visited[i][j] = True
        while q:
            curr = q.popleft()
            cr, cc = curr[0], curr[1]
            for i in range(4):
                nr, nc = cr+dr[i], cc+dc[i]
                if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc] and board[nr][nc] == 1:
                    visited[nr][nc] = True
                    q.append((nr, nc))

    cnt = 0
    for i in range(m):
        for j in range(n):
            if not visited[i][j] and board[i][j] == 1:
                cnt += 1
                expand(i, j, m, n)
    print(cnt)
