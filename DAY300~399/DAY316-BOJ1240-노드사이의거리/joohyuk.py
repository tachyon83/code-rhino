import sys
from collections import deque
si = sys.stdin.readline

n, m = [int(e) for e in si().split()]
g = [[]for _ in range(n+1)]
d, p = [0 for _ in range(n+1)], [[0, 0] for _ in range(n+1)]
for _ in range(n-1):
    a, b, c = [int(e) for e in si().split()]
    g[a].append([b, c])
    g[b].append([a, c])

q = deque()
q.append(1)
while q:
    curr = q.popleft()
    for np in g[curr]:
        if np[0] == p[curr][0]:continue
        d[np[0]] = d[curr]+1
        p[np[0]] = [curr, np[1]]
        q.append(np[0])


def calc(a, b):
    c = 0
    if a == b:return c
    if d[a] > d[b]:a, b = b, a
    while d[a] != d[b]:
        c += p[b][1]
        b = p[b][0]
    while a != b:
        c += p[a][1]+p[b][1]
        a, b = p[a][0], p[b][0]
    return c


while m:
    m -= 1
    a, b = [int(e) for e in si().split()]
    print(calc(a, b))
