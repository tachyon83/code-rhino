import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

N = int(input())

board = []
for _ in range(N):
    board.append(input())

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]
is_in = lambda r, c: 0 <= r < N and 0 <= c < N

def dfs(r, c):
    if board[r][c] == '0': return 0
    if (r, c) in seen: return 0
    seen.add((r, c))
    res = 1
    for d in range(4):
        nr = r + dr[d]
        nc = c + dc[d]
        if is_in(nr, nc):
            res += dfs(nr, nc)
    return res

cnt = 0
lands = []
seen = set()
for i in range(N):
    for j in range(N):
        if (i, j) not in seen and board[i][j] == '1':
            lands.append(dfs(i, j))
            cnt += 1
                
print(cnt)
for i in sorted(lands): print(i)