import sys
import copy
import heapq
from collections import deque
si = sys.stdin.readline

feed, food, land = [], [], []


def spring(n):
    global food, land
    for i in range(n):
        for j in range(n):
            temp, after = copy.deepcopy(land[i][j]), []
            temp.sort()
            for e in temp:
                if e > food[i][j]:
                    food[i][j] += e//2
                else:
                    food[i][j] -= e
                    after.append(e+1)
            land[i][j] = copy.deepcopy(after)


def summer():
    return


def fall(n):
    global land
    dr, dc = [-1, -1, -1, 0, 1, 1, 1, 0], [-1, 0, 1, 1, 1, 0, -1, -1]
    for i in range(n):
        for j in range(n):
            for e in land[i][j]:
                if not e % 5:
                    for idx in range(8):
                        nr, nc = i+dr[idx], j+dc[idx]
                        if 0 <= nr < n and 0 <= nc < n:
                            land[nr][nc].append(1)


def winter(n):
    global feed, food
    for i in range(n):
        for j in range(n):
            food[i][j] += feed[i][j]


def cnt(n):
    global land
    ret = 0
    for i in range(n):
        for j in range(n):
            ret += len(land[i][j])
    return ret


def main():
    global feed, food, land
    n, m, k = [int(e) for e in si().split()]
    feed, land = [], [[[] for _ in range(n)]for _ in range(n)]
    food = [[5 for _ in range(n)]for _ in range(n)]
    for _ in range(n):
        feed.append([int(e) for e in si().split()])
    for _ in range(m):
        x, y, z = [int(e) for e in si().split()]
        land[x-1][y-1].append(z)

    while k:
        k -= 1
        spring(n)
        summer()
        fall(n)
        winter(n)
    print(cnt(n))


if __name__ == '__main__':
    main()
