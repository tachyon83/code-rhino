from collections import defaultdict
import sys

N, M = map(int, sys.stdin.readline().split())
edges = []
for _ in range(M):
    A, B, C = map(int, sys.stdin.readline().split())
    edges.append((C, A, B))
parent = {i:i for i in range(1, N+1)}
rank = defaultdict(int)

def find(node):
    # path compression 기법
    if parent[node] != node:
        parent[node] = find(parent[node])
    return parent[node]


def union(node_v, node_u):
    v_root, u_root = find(node_v), find(node_u)
    
    # union-by-rank 기법
    if rank[v_root] > rank[u_root]:
        parent[u_root] = v_root
    else:
        parent[v_root] = u_root
        if rank[v_root] == rank[u_root]:
            rank[u_root] += 1

def kruskal(edges):
    mst = list()
    
    # 가중치 기준 간선 오름차순 정렬
    edges.sort()
    
    # 정점 연결
    for edge in edges:
        weight, node_v, node_u = edge
        if find(node_v) != find(node_u):
            union(node_v, node_u)
            mst.append(edge)
    
    return mst

ret = kruskal(edges)

total = 0
for r in ret[:-1]:
    total += r[0]
print(total)
