board = []
for _ in range(5):
    board.append(input().split())

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]
is_in = lambda r, c: 0 <= r < 5 and 0 <= c < 5

results = set()
def dfs(r, c, curr):
    if len(curr) == 6:
        results.add(curr)
        return
    for i in range(4):
        nr = r + dr[i]
        nc = c + dc[i]
        if is_in(nr, nc):
            dfs(nr, nc, curr + board[r][c])

for i in range(5):
    for j in range(5):
        dfs(i, j, '')

print(len(results))