import sys

def find(parent, x): #cycle check
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]


def union(parent, a, b): #set
    a = find(parent, a)
    b = find(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

if __name__ == "__main__":
    while True:
        n, m = map(int, sys.stdin.readline().split()) #v, e
        if m == 0 and n == 0:
            break
        parent = [0] * (n+1)
        edges = []
        res = 0

        for i in range(1, n+1):
            parent[i] = i

        for _ in range(m):
            a, b, cost = map(int, sys.stdin.readline().split())
            edges.append((cost, a, b))
        edges.sort()


        sel = []
        for cost, a, b in edges:
            if find(parent, a) != find(parent, b):
                union(parent, a, b)
            else:
                res += cost

        print(res)
