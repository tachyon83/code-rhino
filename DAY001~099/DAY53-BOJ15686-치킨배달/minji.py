import sys
from itertools import combinations

def sol():
    ans = []
    for i in combinations(c, m):
        h_min = 0
        for h_ in h:
            c_load = 10000000
            for j in i:
                if c_load > abs(j[0]-h_[0]) + abs(j[1]-h_[1]):
                    c_load = abs(j[0]-h_[0]) + abs(j[1]-h_[1])
            h_min += c_load
        ans.append(h_min)
    return min(ans)

if __name__ == "__main__":
    n, m = list(map(int, sys.stdin.readline().split()))
    maps = []
    c = []
    h = []
    for i in range(n):
        maps.append(list(map(int, sys.stdin.readline().split())))

    for i in range(n):
        for j in range(n):
            if maps[i][j] == 1:
                h.append((i, j))
            elif maps[i][j] == 2:
                c.append((i, j))

    print(sol())
