import sys
input = sys.stdin.readline

def find(x):
    if x not in root:
        root[x], root_cnt[x] = x, 1
    if x != root[x]:
        root[x] = find(root[x])
    return root[x]

def union(x, y):
    X, Y = find(x), find(y)
    if X != Y:
        root[Y] = X
        root_cnt[X] += root_cnt[Y]
    return X

for _ in range(int(input())):
    root, root_cnt = dict(), dict()
    for _ in range(int(input())):
        x, y = input().split()
        print(root_cnt[union(x, y)])
