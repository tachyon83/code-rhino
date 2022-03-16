
            
W, H = map(int, input().split())

dx, dy = (1, 0, -1, 0), (0, 1, 0, -1)
visited = [[0]*W for _ in range(H)]
sx, sy = 0, 0
dust = []
BOARD = []
for r in range(H):
    row = list(input())
    BOARD.append(row)
    for c in range(W):
        if row[c] == '*':
            dust.append((c, r))
        elif row[c] == 'o':
            sx, sy = c, r
