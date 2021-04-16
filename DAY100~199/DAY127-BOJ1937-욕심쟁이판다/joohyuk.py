import sys
from collections import deque
sys.setrecursionlimit(100000)
si = sys.stdin.readline

n, board, visited, days, ans = int(si()), [], [], [], 0
dr, dc, q = [0, 1, 0, -1], [1, 0, -1, 0], deque()
for _ in range(n):
    board.append([int(e) for e in si().split()])
    visited.append([False for _ in range(n)])
    days.append([0 for _ in range(n)])


def solve(i, j):
    if visited[i][j]:
        return days[i][j]

    curr = 1
    for idx in range(4):
        nr, nc = dr[idx]+i, dc[idx]+j
        if 0 <= nr < n and 0 <= nc < n and board[nr][nc] > board[i][j]:
            curr = max(curr, 1+solve(nr, nc))
    visited[i][j] = True
    days[i][j] = curr
    return curr


for i in range(n):
    for j in range(n):
        if visited[i][j]:
            ans = max(ans, days[i][j])
        else:
            ans = max(ans, solve(i, j))

print(ans)
