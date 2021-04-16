import sys
import copy

def find_max(board):
    global max_val
    for i in range(n):
        for j in range(n):
            if max_val < board[i][j]:
                max_val = board[i][j]

def move_left(board):
    for i in range(n):
        p, x = 0, 0
        for q in range(n):
            if board[i][q] == 0:
                continue
            if x == 0:
                x = board[i][q]
            else:
                if x == board[i][q]:
                    board[i][p] = 2*x
                    p += 1
                    x = 0
                else:
                    board[i][p] = x
                    p += 1
                    x = board[i][q]
            board[i][q] = 0
        if x != 0:
            board[i][p] = x
    return board

def move_right(board):
    for i in range(n):
        p, x = n-1, 0
        for q in range(n-1, -1, -1):
            if board[i][q] == 0:
                continue
            if x == 0:
                x = board[i][q]
            else:
                if x == board[i][q]:
                    board[i][p] = 2*x
                    p -= 1
                    x = 0
                else:
                    board[i][p] = x
                    p -= 1
                    x = board[i][q]
            board[i][q] = 0
        if x != 0:
            board[i][p] = x
    return board

def move_up(board):
    for i in range(n):
        p, x = 0, 0
        for q in range(n):
            if board[q][i] == 0:
                continue
            if x == 0:
                x = board[q][i]
            else:
                if x == board[q][i]:
                    board[p][i] = 2*x
                    p += 1
                    x = 0
                else:
                    board[p][i] = x
                    p += 1
                    x = board[q][i]
            board[q][i] = 0
        if x != 0:
            board[p][i] = x
    return board

def move_down(board):
    for i in range(n):
        p, x = n-1, 0
        for q in range(n-1, -1, -1):
            if board[q][i] == 0:
                continue
            if x == 0:
                x = board[q][i]
            else:
                if x == board[q][i]:
                    board[p][i] = 2*x
                    p -= 1
                    x = 0
                else:
                    board[p][i] = x
                    p -= 1
                    x = board[q][i]
            board[q][i] = 0
        if x != 0:
            board[p][i] = x
    return board

def dfs(board, move_cnt):
    if move_cnt == 5:
        find_max(board)
        return
    dfs(move_left(copy.deepcopy(board)), move_cnt+1)
    dfs(move_right(copy.deepcopy(board)), move_cnt+1)
    dfs(move_up(copy.deepcopy(board)), move_cnt+1)
    dfs(move_down(copy.deepcopy(board)), move_cnt+1)

if __name__ == "__main__":
    max_val = 0
    n = int(sys.stdin.readline())
    board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    dfs(board, 0)
    print(max_val)
