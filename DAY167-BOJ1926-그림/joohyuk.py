import sys
import types
si = sys.stdin.readline
sys.setrecursionlimit(8)

fnOnHand, onHand = 0, 0


def nextRepeatSetter(fn, point):
    global fnOnHand, onHand
    fnOnHand = fn
    onHand = point
    return repeat


def repeat():
    global fnOnHand, onHand
    if not onHand:return
    return nextRepeatSetter(fnOnHand, fnOnHand(onHand))


def initiator(fn):
    while isinstance(fn, types.FunctionType):fn = fn()


def starter(fn, point):
    global fnOnHand, onHand
    fnOnHand = fn
    onHand = point
    initiator(repeat)


cnt, M, n, m, ln, board, vis = 0, 0, 0, 0, 0, [], []
dr, dc, stack = [0, 1, 0, -1], [-1, 0, 1, 0], []


def dfs(p):
    global cnt, n, m, dr, dc, board, vis, stack
    [r, c], ii = p
    for idx in range(ii, 4):
        nr, nc = r+dr[idx], c+dc[idx]
        if 0 <= nr < n and 0 <= nc < m and not vis[nr][nc] and board[nr][nc]:
            vis[nr][nc] = True
            cnt += 1
            if idx < 3:stack.append([[r, c], idx+1])
            return [[nr, nc], 0]


def solve():
    global vis, board, M, cnt
    compCnt = 0
    for i in range(n):
        for j in range(m):
            if not vis[i][j] and board[i][j]:
                vis[i][j] = True
                compCnt += 1
                cnt = 1
                starter(dfs, [[i, j], 0])
                while stack:starter(dfs, stack.pop())
                M = max(M, cnt)
    print(compCnt)
    print(M)


n, m = [int(e) for e in si().split()]
for _ in range(n):
    board.append([int(e) for e in si().split()])
    temp = []
    for i in range(m):temp.append(False)
    vis.append(temp)
    
solve()
