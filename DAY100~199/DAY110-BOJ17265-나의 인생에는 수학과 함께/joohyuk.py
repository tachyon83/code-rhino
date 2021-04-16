import sys
from collections import deque
si = sys.stdin.readline

m, M, board, nums, q = 3125, -21, [], '1234567890', deque()
dr, dc = [0, 1], [1, 0]
n = int(si())
cost = [[[m, M]for _ in range(n)]for _ in range(n)]
for _ in range(n):
    board.append([e for e in si().split()])

v = int(board[0][0])
cost[0][0] = [v, v]
q.append([(0, 0), '*'])
while q:
    curr = q.popleft()
    cr, cc, op = curr[0][0], curr[0][1], curr[1]
    cp = cost[cr][cc]
    for i in range(2):
        nr, nc = cr+dr[i], cc+dc[i]
        if 0 <= nr < n and 0 <= nc < n:
            if board[nr][nc] in nums:
                nv = int(board[nr][nc])
                if op == '+':
                    tempMin, tempMax = cp[0]+nv, cp[1]+nv
                elif op == '-':
                    tempMin, tempMax = cp[0]-nv, cp[1]-nv
                else:
                    tempMin, tempMax = cp[0]*nv, cp[1]*nv

                cost[nr][nc][0] = min(cost[nr][nc][0], tempMin)
                cost[nr][nc][1] = max(cost[nr][nc][1], tempMax)
                q.append([(nr, nc), '*'])
            else:
                cost[nr][nc][0] = min(cost[nr][nc][0], cp[0])
                cost[nr][nc][1] = max(cost[nr][nc][1], cp[1])
                q.append([(nr, nc), board[nr][nc]])

print(cost[n-1][n-1][1], cost[n-1][n-1][0])
