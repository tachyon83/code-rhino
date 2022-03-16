'''
문제로 나오면 못풀삘...
'''

import sys
#sys.stdin = open("input.txt", "r")
N = int(sys.stdin.readline())
board = [sys.stdin.readline().strip() for _ in range(N)]

def quad(x1, y1, x2, y2, n):
    if n == 1:
        return board[y1][x1]
    a = n // 2
    r1 = quad(x1, y1, x1 + a, y1 + a, a)
    r2 = quad(x1 + a, y1, x1 + n, y1 + a, a)
    r3 = quad(x1, y1 + a, x1 + a, y1 + n, a)
    r4 = quad(x1 + a, y1 + a, x1 + n, y1 + n, a)
    if r1 == r2 == r3 == r4 and len(r1) == 1:
        return r1
    return "(" + r1 + r2 + r3 + r4 + ")"
print(quad(0, 0, N, N, N))
