import sys
input = sys.stdin.readline


def find(x):
    if parent[x] < 0:
        return x
    y = find(parent[x])
    parent[x] = y
    return y


def union(x, y):
    x = find(x)
    y = find(y)
    if y == x:
        return -1 * parent[x]
    parent[x] += parent[y]
    parent[y] = x
    return -1 * parent[x]


t = int(input())
for _ in range(t):
    n = int(input())
    name = {}
    cnt = 0
    parent = []
    for _ in range(n):
        temp = list(map(str, input().strip().split()))
        for a in temp:
            if name.get(a) is None:
                name[a] = cnt
                parent.append(-1)
                cnt += 1

        print(union(name[temp[0]], name[temp[1]]))
