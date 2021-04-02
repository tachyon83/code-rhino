import sys
si = sys.stdin.readline

root, route, ans = [0], [], 0


def union(a, b):
    global root
    a, b = find(a), find(b)
    root[a] = b


def find(a):
    global root
    if root[a] == a:
        return a
    root[a] = find(root[a])
    return root[a]


n = int(si())
for i in range(n):
    root.append(i+1)
    temp = [int(e) for e in si().split()]
    for j in range(i+1, n):
        route.append([temp[j], [i+1, j+1]])
route.sort()
for e in route:
    if find(e[1][0]) != find(e[1][1]):
        ans += e[0]
        union(e[1][0], e[1][1])
print(ans)
