import sys
import bisect
from collections import deque
si = sys.stdin.readline

n, stack, nl = int(si()), deque(), []
l = [int(e) for e in si().split()]
for e in l:
    idx = bisect.bisect_left(nl, e)
    if idx == len(nl):
        nl.append(e)
    else:
        nl[idx] = e
    stack.append((idx, e))
idx = len(nl)
print(idx)
idx -= 1
while stack:
    curr = stack.pop()
    if idx == curr[0]:
        nl[idx] = curr[1]
        idx -= 1
print(*nl)
