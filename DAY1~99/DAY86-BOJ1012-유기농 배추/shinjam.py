

def check(x, y):
    BOARD[y][x] = 0

    for v in (1, 0), (0, 1), (-1, 0), (0, -1):
        nx, ny = x+v[0], y+v[1]
        if 0 <= nx < COL and 0 <= ny < ROW and BOARD[ny][nx]:
            check(nx, ny)


def solve(col, row, k):
    global COL, ROW, K, BOARD

    board = list([0]*col for _ in range(row))
    COL, ROW, K, BOARD = col, row, k, board

    for _ in range(k):
        c, r = map(int, input().split())
        BOARD[r][c] = 1

    ans = 0
    for i in range(ROW):
        for j in range(COL):
            if BOARD[i][j]:
                ans += 1
                check(j, i)

    return ans


for _ in range(int(input())):
    print(solve(*map(int, input().split())))
