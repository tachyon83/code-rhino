def solution(rows, columns, queries):
    def getMinWithRotate(r1, c1, r2, c2):
        ret = float('INF')
        r1c2 = board[r1][c2]
        r2c2 = board[r2][c2]
        r2c1 = board[r2][c1]

        ret = min(r1c2, r2c2, r2c1)

        for i in range(c2, c1, -1):
            board[r1][i] = board[r1][i - 1]
            ret = min(ret, board[r1][i])
        for i in range(r2, r1 + 1, -1):
            board[i][c2] = board[i - 1][c2]
            ret = min(ret, board[i][c2])
        for i in range(c1, c2 - 1, 1):
            board[r2][i] = board[r2][i + 1]
            ret = min(ret, board[r2][i])
        for i in range(r1, r2 -1, 1):
            board[i][c1] = board[i + 1][c1]
            ret = min(ret, board[i][c1])

        board[r1 + 1][c2] = r1c2
        board[r2][c2 - 1] = r2c2
        board[r2 - 1][c1] = r2c1

        return ret

    board = [[j for j in range(1 + (columns * i), columns + (columns * i) + 1)] for i in range(rows)]

    ans = []
    for r1, c1, r2, c2 in queries:
        ans.append(getMinWithRotate(r1 - 1, c1 - 1, r2 - 1, c2 - 1))
    
    return ans