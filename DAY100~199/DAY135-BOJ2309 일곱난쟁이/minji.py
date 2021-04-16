import sys
from itertools import combinations

def sol():
    for i in (combinations(t, 7)):
        if sum(i) == 100:
            i = sorted(list(i))
            for j in i:
                print(j)
            return

if __name__ == "__main__":
    t = [0 for _ in range(9)]
    for i in range(9):
        t[i] = int(sys.stdin.readline())
    sol()
