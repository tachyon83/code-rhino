import sys
si = sys.stdin.readline


sz, root, flag, origin = 1000+1, [], 0, (500, 500)
for i in range(sz):
    temp = []
    for j in range(sz):
        temp.append([i, j])
    root.append(temp)


def checkpath(x1, y1, x2, y2):
    global origin, flag
    for i in range(x1, x2+1):
        if not flag and (i, y1) == origin:
            flag = 1
        if not flag and (i, y2) == origin:
            flag = 1
        union(x1, y1, i, y1)
        union(x1, y1, i, y2)

    for i in range(y1+1, y2):
        if not flag and (x1, i) == origin:
            flag = 1
        if not flag and (x2, i) == origin:
            flag = 1
        union(x1, y1, x1, i)
        union(x1, y1, x2, i)


def find(x, y):
    global root
    if root[x][y] == [x, y]:
        return [x, y]
    root[x][y] = find(root[x][y][0], root[x][y][1])
    return root[x][y]


def union(x1, y1, x2, y2):
    global root, ans
    root_a, root_b = find(x1, y1), find(x2, y2)
    if root_b == [x2, y2]:
        if tuple(root_b) in ans:
            ans.remove(tuple(root_b))
        root[root_b[0]][root_b[1]] = root_a
        return
    if tuple(root_a) in ans:
        ans.remove(tuple(root_a))
    root[root_a[0]][root_a[1]] = root_b


n, ans = int(si()), set()
while n:
    n -= 1
    x1, y1, x2, y2 = [int(e)+500 for e in si().split()]
    checkpath(x1, y1, x2, y2)
    ans.add(tuple(find(x1, y1)))
print(len(ans)-flag)
