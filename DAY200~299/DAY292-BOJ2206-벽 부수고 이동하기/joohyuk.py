import sys
from collections import deque
si = sys.stdin.readline

n, m = [int(e) for e in si().split()]
big = int(1e6)+5
board, cost = [], [[[big, big]for _ in range(m)]for _ in range(n)]
for _ in range(n):
    row = [int(e) for e in si().strip()]
    board.append(row)

dr, dc = [0, 1, 0, -1], [1, 0, -1, 0]
q = deque()
q.append([0, 0])
cost[0][0] = [1, 0]
while q:
    cr, cc = q.popleft()

    for idx in range(4):
        nr, nc = cr+dr[idx], cc+dc[idx]
        if 0 <= nr < n and 0 <= nc < m:
            if not board[nr][nc]:
                flag = False
                if cost[cr][cc][0] < big and cost[nr][nc][0] == big:
                    cost[nr][nc][0] = cost[cr][cc][0]+1
                    flag = True
                if cost[cr][cc][1] < big and cost[cr][cc][1]+1 < cost[nr][nc][1]:
                    cost[nr][nc][1] = cost[cr][cc][1]+1
                    flag = True
                if flag:
                    q.append([nr, nc])
            else:
                if cost[cr][cc][0]+1 < cost[nr][nc][1]:
                    cost[nr][nc][1] = cost[cr][cc][0]+1
                    q.append([nr, nc])

ans = min(cost[n-1][m-1])
print(ans if ans != big else -1)
