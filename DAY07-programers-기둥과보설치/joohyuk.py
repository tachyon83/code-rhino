board = [[[0, 0] for _ in range(100+1)]for _ in range(100+1)]


def singlecheck(x, y, t, n):
    if t:
        if (y-1 >= 0 and board[x][y-1][1]) and (y+1 <= n and board[x][y+1][1]):
            return True
        if x-1 >= 0 and (board[x-1][y][0] or board[x-1][y+1][0]):
            return True
    else:
        if not x:
            return True
        if x-1 >= 0 and board[x-1][y][0]:
            return True
        if board[x][y][1] or (y-1 >= 0 and board[x][y-1][1]):
            return True
    return False


def totalcheck(n):
    for i in range(n+1):
        for j in range(n+1):
            for k in range(2):
                if board[i][j][k]:
                    board[i][j][k] -= 1
                    if not singlecheck(i, j, k, n):
                        board[i][j][k] += 1
                        return False
                    board[i][j][k] += 1
    return True


def solution(n, build_frame):
    for e in build_frame:
        y, x, a, b = e
        if b:
            if singlecheck(x, y, a, n):
                board[x][y][a] += 1
        else:
            board[x][y][a] -= 1
            if not totalcheck(n):
                board[x][y][a] += 1

    answer = []
    for j in range(n+1):
        for i in range(n+1):
            for k in range(2):
                if board[i][j][k]:
                    answer.append((j, i, k))

    return answer
