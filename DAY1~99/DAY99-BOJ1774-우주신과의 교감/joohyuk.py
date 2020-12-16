import sys
from math import sqrt
si = sys.stdin.readline

n, m = [int(e) for e in si().split()]
root = [e for e in range(n+1)]
points = [0 for _ in range(n+1)]
routes = []


def find(a):
    global root
    if root[a] == a:
        return a
    root[a] = find(root[a])
    return root[a]


def union(a, b):
    a, b = find(a), find(b)
    if a != b:
        root[a] = b


def distance(p1, p2):
    p1x, p1y = p1[0], p1[1]
    p2x, p2y = p2[0], p2[1]
    return sqrt((p1x-p2x)**2+(p1y-p2y)**2)


for i in range(1, n+1):
    points[i] = [int(e) for e in si().split()]
for i in range(1, n+1):
    for j in range(i, n+1):
        if i != j:
            routes.append([distance(points[i], points[j]), i, j])
routes.sort()

while m:
    m -= 1
    a, b = [int(e) for e in si().split()]
    union(a, b)

t = 0
for route in routes:
    s, e = route[1], route[2]
    if find(s) != find(e):
        union(s, e)
        t += route[0]
print("{:.2f}".format(t))
