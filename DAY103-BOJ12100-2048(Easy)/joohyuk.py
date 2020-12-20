import sys
import copy
si = sys.stdin.readline


def dirdfs(dirs, i):
    if i == 5:
        solve(dirs)
        return
    for e in [1, 2, 3, 4]:
        dirdfs(dirs+[e], i+1)


def up():
    global n, boardcopy, m
    for j in range(0, n):
        hold, hr, hc = 0, 0, 0
        for i in range(0, n):
            if boardcopy[i][j]:
                if hold == boardcopy[i][j]:
                    boardcopy[hr][hc] *= 2
                    # m = max(m, boardcopy[hr][hc])
                    hold = 0
                    boardcopy[i][j] = 0
                else:
                    hold = boardcopy[i][j]
                    hr, hc = i, j

        pos = 0
        for i in range(0, n):
            if boardcopy[i][j]:
                temp = boardcopy[i][j]
                boardcopy[i][j] = 0
                boardcopy[pos][j] = temp
                pos += 1


def down():
    global n, boardcopy, m
    for j in range(0, n):
        hold, hr, hc = 0, 0, 0
        for i in range(n-1, -1, -1):
            if boardcopy[i][j]:
                if hold == boardcopy[i][j]:
                    boardcopy[hr][hc] *= 2
                    # m = max(m, boardcopy[hr][hc])
                    hold = 0
                    boardcopy[i][j] = 0
                else:
                    hold = boardcopy[i][j]
                    hr, hc = i, j

        pos = n-1
        for i in range(n-1, -1, -1):
            if boardcopy[i][j]:
                temp = boardcopy[i][j]
                boardcopy[i][j] = 0
                boardcopy[pos][j] = temp
                pos -= 1


def left():
    global n, boardcopy, m
    for i in range(0, n):
        hold, hr, hc = 0, 0, 0
        for j in range(0, n):
            if boardcopy[i][j]:
                if hold == boardcopy[i][j]:
                    boardcopy[hr][hc] *= 2
                    # m = max(m, boardcopy[hr][hc])
                    hold = 0
                    boardcopy[i][j] = 0
                else:
                    hold = boardcopy[i][j]
                    hr, hc = i, j

        pos = 0
        for j in range(0, n):
            if boardcopy[i][j]:
                temp = boardcopy[i][j]
                boardcopy[i][j] = 0
                boardcopy[i][pos] = temp
                pos += 1


def right():
    global n, boardcopy, m
    for i in range(0, n):
        hold, hr, hc = 0, 0, 0
        for j in range(n-1, -1, -1):
            if boardcopy[i][j]:
                if hold == boardcopy[i][j]:
                    boardcopy[hr][hc] *= 2
                    # m = max(m, boardcopy[hr][hc])
                    hold = 0
                    boardcopy[i][j] = 0
                else:
                    hold = boardcopy[i][j]
                    hr, hc = i, j

        pos = n-1
        for j in range(n-1, -1, -1):
            if boardcopy[i][j]:
                temp = boardcopy[i][j]
                boardcopy[i][j] = 0
                boardcopy[i][pos] = temp
                pos -= 1


def solve(dirs):
    global board, boardcopy, m
    boardcopy = copy.deepcopy(board)
    for e in dirs:
        if e == 1:
            up()
        elif e == 2:
            down()
        elif e == 3:
            left()
        else:
            right()
    for row in boardcopy:
        for e in row:
            m = max(m, e)


n, m, board, boardcopy = int(si()), 0, [], []
for _ in range(n):
    board.append([int(e) for e in si().split()])
dirdfs([], 0)
print(m)
