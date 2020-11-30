import sys
si = sys.stdin.readline

board, sz = [], 8
n, m = [int(e) for e in si().split()]
for _ in range(n):
    board.append(si()[:-1])


def cnt(a, b):
    global board, sz
    v1, v2 = 0, 0
    sl1, sl2 = 'B', 'W'
    for i in range(sz):
        if i:
            if sl1 == 'B':
                sl1 = 'W'
            else:
                sl1 = 'B'
            if sl2 == 'W':
                sl2 = 'B'
            else:
                sl2 = 'W'

        for j in range(sz):
            if board[a+i][b+j] != sl1:
                v1 += 1
            if sl1 == 'B':
                sl1 = 'W'
            else:
                sl1 = 'B'
            if board[a+i][b+j] != sl2:
                v2 += 1
            if sl2 == 'W':
                sl2 = 'B'
            else:
                sl2 = 'W'
    return min(v1, v2)


ans = 50*50+1
for i in range(n-sz+1):
    for j in range(m-sz+1):
        ans = min(ans, cnt(i, j))
print(ans)
