import sys
from collections import deque
si = sys.stdin.readline
sys.setrecursionlimit(1000+1)


def find(a):
    global root
    if root[a] == a:
        return a
    root[a] = find(root[a])
    return root[a]


n, m = [int(e) for e in si().split()]
root = [i for i in range(n+1)]
road, hold, k, flag = [], 0, 0, False

for i in range(m+1):
    a, b, c = [int(e) for e in si().split()]
    if not i:
        if not c:
            flag = True
        continue
    road.append((c, (a, b)))

road.sort()
for e in road:
    a, b = e[1]
    a, b = find(a), find(b)
    if a != b:
        root[a] = b
        if not e[0]:
            k += 1
if flag:
    k += 1
hold = k*k

root, k = [i for i in range(n+1)], 0
for i in range(m-1, -1, -1):
    a, b = road[i][1]
    a, b = find(a), find(b)
    if a != b:
        root[a] = b
        if not road[i][0]:
            k += 1

if flag:
    k += 1
print(hold-k*k)
