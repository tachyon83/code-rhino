# -*- coding: utf-8 -*-
import sys
from itertools import combinations

def sol():
    cnt = 50000
    for c1, c2, c3 in combinations(seed, 3):
        c = c1 + c2 + c3
        n_c = set(c)
        if len(n_c) != 15:
            continue

        sum_ = 0
        for i in list(n_c):
            a = i[0]
            b = i[1]
            sum_ += maps[a][b]

        if sum_ < cnt:
            cnt = sum_
    print(cnt)

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    maps = []
    for i in range(n):
        maps.append(list(map(int, sys.stdin.readline().split())))
    seed = []
    for y in range(1, n-1):
        for x in range(1, n-1):
            seed.append([(y, x), (y, x+1), (y-1, x), (y, x-1), (y+1, x)])

    sol()
