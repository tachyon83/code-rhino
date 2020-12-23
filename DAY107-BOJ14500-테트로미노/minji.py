# -*- coding: utf-8 -*-
import sys
tetromino = [
    [(0,0), (0,1), (1,0), (1,1)], # ㅁ
    [(0,0), (0,1), (0,2), (0,3)], # ㅡ
    [(0,0), (1,0), (2,0), (3,0)], # ㅣ
    [(0,0), (0,1), (0,2), (1,0)],
    [(1,0), (1,1), (1,2), (0,2)],
    [(0,0), (1,0), (1,1), (1,2)], # ㄴ
    [(0,0), (0,1), (0,2), (1,2)], # ㄱ
    [(0,0), (1,0), (2,0), (2,1)],
    [(2,0), (2,1), (1,1), (0,1)],
    [(0,0), (0,1), (1,0), (2,0)],
    [(0,0), (0,1), (1,1), (2,1)],
    [(0,0), (0,1), (0,2), (1,1)], # ㅜ
    [(1,0), (1,1), (1,2), (0,1)], # ㅗ
    [(0,0), (1,0), (2,0), (1,1)], # ㅏ
    [(1,0), (0,1), (1,1), (2,1)], # ㅓ
    [(1,0), (2,0), (0,1), (1,1)],
    [(0,0), (1,0), (1,1), (2,1)],
    [(1,0), (0,1), (1,1), (0,2)],
    [(0,0), (0,1), (1,1), (1,2)]
]
def find(x, y):
    global result
    for i in range(19):
        answer = 0
        for j in range(4):
            a = x + tetromino[i][j][0]
            b = y + tetromino[i][j][1]
            if 0 <= a < n and 0 <= b < m:
                answer += maps[a][b]
        if result < answer:
            result = answer
def sol():
    for i in range(n):
        for j in range(m):
            find(i, j)
if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    maps = []
    result = 0
    for i in range(n):
        maps.append(list(map(int, sys.stdin.readline().split())))
    sol()
    print(result)
