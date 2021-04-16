import sys
si = sys.stdin.readline
notVisited = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
              'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]
cnt, M = 0, 0

def backtrack(r, c):
    global M, R, C
    if board[r][c] in notVisited:
        notVisited.remove(board[r][c])

    for i in range(4):
        rn, cn = r+dr[i], c+dc[i]
        if rn >= 0 and rn < R and cn >= 0 and cn < C and board[rn][cn] in notVisited:
            backtrack(rn, cn)

    M = max(26-len(notVisited), M)
    notVisited.add(board[r][c])

l = [int(e) for e in si().split()]
R, C = l[0], l[1]
board = [list(si().strip()) for _ in range(R)]
backtrack(0, 0)
print(M)
