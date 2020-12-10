import sys
from collections import deque
si = sys.stdin.readline
dr, dc = [0, 1, 0, -1], [1, 0, -1, 0]

while True:
    w, h = [int(e) for e in si().split()]
    if not w:
        break
    board, dust, ans = [], 0, 0
    for i in range(h):
        row = [e for e in si().strip()]
        for j, e in enumerate(row):
            if e == '*':
                dust += 1
            elif e == 'o':
                start = (i, j)

        board.append(row)

    flag = True
    while flag and dust:
        flag, d = False, 0
        visited = [[False for _ in range(w)]for _ in range(w)]
        sr, sc = start[0], start[1]
        visited[sr][sc] = True
        board[sr][sc] = '.'
        q = deque()
        q.append(start)
        while q:
            qs = len(q)
            d += 1
            for _ in range(qs):
                curr = q.popleft()
                cr, cc = curr[0], curr[1]
                for i in range(4):
                    nr, nc = cr+dr[i], cc+dc[i]
                    if 0 <= nr < h and 0 <= nc < w and board[nr][nc] != 'x' and not visited[nr][nc]:
                        visited[nr][nc] = True
                        if board[nr][nc] == '*':
                            ans += d
                            flag = True
                            dust -= 1
                            start = (nr, nc)
                            break
                        else:
                            q.append((nr, nc))
                if flag:
                    break
            if flag:
                break
    if dust:
        print(-1)
    else:
        print(ans)
