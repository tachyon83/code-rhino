import sys
si = sys.stdin.readline
sys.setrecursionlimit(100000)

while True:
    m, n = [int(e) for e in si().split()]
    if not m:
        break
    l, root, tot = [], [e for e in range(m)], 0
    for _ in range(n):
        x, y, z = [int(e) for e in si().split()]
        tot += z
        l.append([z, x, y])
    l.sort()

    def union(a, b):
        a = find(a)
        b = find(b)
        if a == b:
            return
        root[a] = b

    def find(a):
        if root[a] == a:
            return a
        root[a] = find(root[a])
        return root[a]

    t = 0
    for route in l:
        z, x, y = route
        if find(x) != find(y):
            union(x, y)
            t += z
    print(tot-t)
