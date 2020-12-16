import sys
si = sys.stdin.readline

n, board, cost, cnt, exp = int(si()), [], 3000+1, 0, 0
dr, dc = [0, 1, 0, -1], [-1, 0, 1, 0]
for _ in range(n):
    row = [int(e) for e in si().split()]
    board.append(row)
upto = (n-2)*(n-2)
visited = [[False for _ in range(n)]for _ in range(n)]


def is_blank(i, j):
    global visited, dr, dc
    if visited[i][j]:
        return False
    for idx in range(4):
        ni, nj = i+dr[idx], j+dc[idx]
        if visited[ni][nj]:
            return False
    return True


def buy(i, j):
    global board, dr, dc, exp, visited
    exp += board[i][j]
    visited[i][j] = True
    for idx in range(4):
        ni, nj = i+dr[idx], j+dc[idx]
        exp += board[ni][nj]
        visited[ni][nj] = True


def sell(i, j):
    global board, dr, dc, exp, visited
    exp -= board[i][j]
    visited[i][j] = False
    for idx in range(4):
        ni, nj = i+dr[idx], j+dc[idx]
        exp -= board[ni][nj]
        visited[ni][nj] = False


def flower(num):
    global visited, cost, board, n, cnt, exp, upto
    if cnt == 3:
        cost = min(cost, exp)
        return
    for idx in range(num, upto):
        i, j = idx//(n-2)+1, idx % (n-2)+1
        if is_blank(i, j):
            cnt += 1
            buy(i, j)
            flower(idx+1)
            cnt -= 1
            sell(i, j)


flower(0)
print(cost)
