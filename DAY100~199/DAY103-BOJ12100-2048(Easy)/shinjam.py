from collections import deque
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def transform(v, board):
    new_board = board
    if v == 0:  # 동
        new_board = list(map(lambda x: x[::-1], board))
    elif v == 2:  # 남
        new_board = list(zip(*board[::-1]))
    elif v == 3:  # 북
        new_board = list(zip(*board))
    return new_board


def move(v, board):
    global ans
    t_board = transform(v, board)
    n_board = list([0]*N for _ in range(N))
    for i in range(N):
        j = 0
        queue = deque(filter(bool, t_board[i]))
        while queue:
            x = queue.popleft()
            if not n_board[i][j]:
                n_board[i][j] = x
            elif n_board[i][j] == x:
                n_board[i][j] = x*2 
                j += 1 
            else: 
                j += 1
                n_board[i][j] = x 

    ans = max(ans, max(map(max, n_board)))
    return n_board


def dfs(board, stage=0):
    if stage == 5:
        return
    for v in range(4):
        n_board = move(v, board)
        dfs(n_board, stage+1)


N = int(input())
BOARD = list(list(map(int, input().split())) for _ in range(N))
ans = 0
dfs(BOARD)
print(ans)
