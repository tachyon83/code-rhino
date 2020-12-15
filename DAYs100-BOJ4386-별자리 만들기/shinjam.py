from itertools import combinations
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

N = int(input())
pos = list(tuple(map(float, input().split())) for _ in range(N))
parent = list(i for i in range(N))
edges = []
for a, b in combinations(range(N), 2):
    edges.append((distance(pos[a], pos[b]), a, b))
edges.sort()

ans = 0
for d, a, b in edges:
    if find(a) != find(b):
        union(a, b)
        ans += d
print(f'{ans:.2f}')
    
