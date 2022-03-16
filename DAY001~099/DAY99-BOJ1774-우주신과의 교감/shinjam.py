from math import sqrt
import sys
input = sys.stdin.readline

def distance(a, b):
    return sqrt((a[0]-b[0])**2 + (a[1]-b[1])**2)
    

def find(node):
    if parent[node] != node:
        parent[node] = find(parent[node])
    return parent[node]

def union(node_a, node_b):
    parent_a, parent_b = find(node_a), find(node_b)
    
    if parent_a != parent_b:
        parent[parent_b] = parent_a


N, M = map(int, input().split())
POS = {i:tuple(map(int, input().split())) for i in range(1, N+1)}
parent = {i:i for i in range(1, N+1)}
for _ in range(M):
    a, b = map(int, input().split())
    union(a, b)
    
edges = []
for i in range(1, N+1):
    for j in range(1, N+1):
        if i != j:
            edges.append((distance(POS[i], POS[j]), i, j))
edges.sort()


ans = 0
for d, a, b in edges:
    if find(a) != find(b):
        union(a, b)
        ans += d
print(f'{ans:.2f}')
