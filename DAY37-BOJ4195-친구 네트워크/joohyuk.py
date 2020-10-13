import sys
from collections import deque
si = sys.stdin.readline


def find(a):
    if root[a] < 0:
        return a
    else:
        root[a] = find(root[a])
        return root[a]


def merge(a, b):
    a = find(a)
    b = find(b)
    if a != b:
        if a < b:
            root[b] = a
            network[a] += network[b]
        else:
            root[a] = b
            network[b] += network[a]


t = int(si())
for _ in range(t):
    m = int(si())
    root = [-1]*m*2
    n = 1
    friends = dict()
    network = dict()
    for _ in range(m):
        l = [e for e in si().split()]
        p1, p2 = l[0], l[1]
        if p1 not in friends:
            friends[p1] = n
            if n not in network:
                network[n] = 1
            n += 1
        if p2 not in friends:
            friends[p2] = n
            if n not in network:
                network[n] = 1
            n += 1
        merge(friends[p1], friends[p2])
        print(network[find(friends[p1])])
