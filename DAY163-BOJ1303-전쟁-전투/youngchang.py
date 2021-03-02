N, M = map(int, input().split())

board = []
for _ in range(M):
    board.append(input())

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]
is_in = lambda r, c: 0 <= r < M and 0 <= c < N

def dfs(r, c, char):
    if board[r][c] != char: return 0
    if (r, c) in seen: return 0
    seen.add((r, c))
    res = 1
    for d in range(4):
        nr = r + dr[d]
        nc = c + dc[d]
        if is_in(nr, nc):
            res += dfs(nr, nc, char)
    return res

W = B = 0
seen = set()
for i in range(M):
    for j in range(N):
        if (i, j) not in seen:
            char = board[i][j]
            point = dfs(i, j, char) ** 2
            if char == 'W':
                W += point
            else:
                B += point
                
print(W, B)