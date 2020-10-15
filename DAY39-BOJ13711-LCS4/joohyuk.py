import sys
import bisect
si = sys.stdin.readline

n = int(si())
l, a = [int(e) for e in si().split()], [0 for _ in range(n+1)]
for i in range(n):
    a[l[i]] = i
l = [int(e) for e in si().split()]
ret = [a[l[0]]]
for e in l:
    idx = bisect.bisect_left(ret, a[e])
    if idx == len(ret):
        ret.append(a[e])
    else:
        ret[idx] = a[e]
print(len(ret))
