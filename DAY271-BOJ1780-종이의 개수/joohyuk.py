import sys
si = sys.stdin.readline

ans = [0, 0, 0]
n, board = int(si()), []
for _ in range(n):
    board.append([int(e) for e in si().split()])


def det(rs, re, cs, ce):
    v, flag = board[rs][cs], False
    for i in range(rs, re):
        for j in range(cs, ce):
            if board[i][j] != v:
                flag = True
                break
        if flag:break

    if not flag:
        ans[v+1] += 1
        return
    temp = (re-rs)//3
    for i in range(3):
        for j in range(3):
            det(rs+i*temp, rs+(i+1)*temp, cs+j*temp, cs+(j+1)*temp)


det(0, n, 0, n)
for e in ans:print(e)
