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

V, E = map(int, input().split())

parent = {v:v for v in range(1,V+1)}
edges = []
for _ in range(E):
    a, b, w = map(int, input().split())
    edges.append((w, a, b))
edges.sort()


ans = 0
for edge in edges:
    w, v, u = edge
    if find(v) != find(u):
        union(v, u)
        ans += w
print(ans)
