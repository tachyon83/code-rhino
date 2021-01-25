import sys
from itertools import combinations

input = sys.stdin.readline

dwarfs = [int(input()) for _ in range(9)]
total = sum(dwarfs)

for i in combinations(dwarfs, 2):
    if total - sum(i) == 100:
        dwarfs.remove(i[0])
        dwarfs.remove((i[1]))
        break

for i in sorted(dwarfs):
    print(i)
