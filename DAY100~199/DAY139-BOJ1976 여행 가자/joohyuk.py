import sys
si = sys.stdin.readline

n = int(si())
m = int(si())
root = [e for e in range(n+1)]


def find(a):
    if root[a] == a:
        return a
    root[a] = find(root[a])
    return root[a]


def union(a, b):
    a, b = find(a), find(b)
    root[a] = b


for i in range(n):
    temp = [int(e) for e in si().split()]
    for j in range(n):
        if i == j:
            continue
        if temp[j]:
            union(i+1, j+1)

flag = False
routes = [int(e) for e in si().split()]
for i in range(m-1):
    if find(routes[i]) != find(routes[i+1]):
        print('NO')
        flag = True
        break
if not flag:
    print('YES')
