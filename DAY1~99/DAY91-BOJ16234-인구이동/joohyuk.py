import sys
from collections import deque
si = sys.stdin.readline

n, l, r = [int(e) for e in si().split()]
board, flag, num, plan, visited, ans, store = [], True, 0, dict(), [], 0, []
for _ in range(n):
    board.append([int(e) for e in si().split()])


def check(i, j):
    global l, r, flag, num, plan, n, visited, board, store
    q, dr, dc, border = deque(), [0, 1, 0, -1], [1, 0, -1, 0], False
    visited[i][j] = True
    q.append((i, j))
    while q:
        curr = q.popleft()
        cr, cc = curr[0], curr[1]
        for idx in range(4):
            nr, nc = cr+dr[idx], cc+dc[idx]
            if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc]:
                diff = abs(board[cr][cc]-board[nr][nc])
                if l <= diff <= r:
                    visited[nr][nc] = True
                    q.append((nr, nc))
                    flag = True
                    if not border:
                        num += 1
                        border = True
                        plan[num] = dict()
                        plan[num]['cnt'] = 1
                        plan[num]['sum'] = board[cr][cc]
                        store[cr][cc] = num
                    plan[num]['cnt'] += 1
                    plan[num]['sum'] += board[nr][nc]
                    store[nr][nc] = num


while flag:
    flag, plan, num = False, dict(), 0
    visited = [[False for _ in range(n)]for _ in range(n)]
    store = [[0 for _ in range(n)]for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                check(i, j)
    if len(plan):
        ans += 1
    for i in range(n):
        for j in range(n):
            if store[i][j] in plan:
                temp = store[i][j]
                board[i][j] = plan[temp]['sum']//plan[temp]['cnt']
print(ans)
