import sys

input = sys.stdin.readline

def find(node):
    if parent[node] != node:
        parent[node] = find(parent[node])
    return parent[node]


def union(node_v, node_u):
    v_root, u_root = find(node_v), find(node_u)

    if v_root != u_root:
        parent[u_root] = v_root


while True:
    m, n = map(int, input().split())
    if m == n == 0:
        break
    edges = []
    ans = 0
    for _ in range(n):
        x, y, z = map(int, input().split())
        ans += z
        edges.append((z, x, y))
    edges.sort()

    parent = {v: v for v in range(n)}

    for z, x, y in edges:
        if find(x) != find(y):
            union(x, y)
            ans -= z
    print(ans)
