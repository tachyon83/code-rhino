import sys

t = int(sys.stdin.readline())


def find(node):
    if parent[node] != node:
        parent[node] = find(parent[node])
    return parent[node]


def union(node1, node2):
    nw1 = find(node1)
    nw2 = find(node2)

    parent[nw2] = nw1
    number[nw1] += number[nw2]


for _ in range(t):
    f = int(sys.stdin.readline())
    number = dict()
    parent = dict()
    for i in range(f):
        node1, node2 = sys.stdin.readline().split()
        if node1 not in parent:
            parent[node1] = node1
            number[node1] = 1
        if node2 not in parent:
            parent[node2] = node2
            number[node2] = 1

        if find(node1) != find(node2):
            union(node1, node2)

        print(number[parent[node1]])
