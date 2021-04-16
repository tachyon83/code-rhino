import sys
import bisect
si = sys.stdin.readline

n = int(si())
l = [int(e) for e in si().split()]

l = l[::-1]
sl = []
for e in l:
    i = bisect.bisect_left(sl, e)
    if i >= len(sl):
        sl.append(e)
    else:
        sl[i] = e
print(len(sl))
