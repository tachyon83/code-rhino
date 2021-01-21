import sys
from itertools import combinations as cb
si = sys.stdin.readline

dwarves = []
for _ in range(9):dwarves.append(int(si()))
picks = cb(dwarves, 7)
for pick in picks:
    h = 0
    for i in pick:h += i
    if h == 100:
        pick=list(pick)
        pick.sort()
        for num in pick:print(num)
        break
