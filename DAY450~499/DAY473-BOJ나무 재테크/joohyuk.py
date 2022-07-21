import sys
import copy
si = sys.stdin.readline


def solve():
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
        dr, dc = [-1, -1, -1, 0, 1, 1, 1, 0], [-1, 0, 1, 1, 1, 0, -1, -1]
        for i in range(n):
            for j in range(n):
                temp, dead, nt = land[i][j], 0, []
                if len(temp):
                    temp.sort()
                    for tree in temp:
                        if tree > food[i][j]:
                            dead += tree//2
                        else:
                            food[i][j] -= tree
                            nt.append(tree+1)
                    land[i][j] = copy.deepcopy(nt)
                food[i][j] += dead+feed[i][j]

        for i in range(n):
            for j in range(n):
                temp = land[i][j]
                if len(temp):
                    for e in temp:
                        if not e % 5:
                            for idx in range(8):
                                nr, nc = i+dr[idx], j+dc[idx]
                                if 0 <= nr < n and 0 <= nc < n:
                                    land[nr][nc].append(1)

    ret = 0
    for i in range(n):
        for j in range(n):
            ret += len(land[i][j])
    print(ret)
solve()
