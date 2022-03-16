import sys
import bisect
si = sys.stdin.readline
n, l = int(si()), [int(e) for e in si().split()]
nl = [l[0]]
for i in range(1, len(l)):
    idx = bisect.bisect_left(nl, l[i])
    if idx == len(nl):
        nl.append(l[i])
    else:
        nl[idx] = l[i]
print(len(nl))
