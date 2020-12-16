from collections import defaultdict
import sys 

def find(node):
    if parent[node] != node:
        parent[node] = find(parent[node])
        
    return parent[node]


V, E = map(int, sys.stdin.readline().split())

adj = [0]*(V+1)
parent = {i:i for i in range(1, V+1)}
ret = 0

for _ in range(E):
    a, b = map(int, sys.stdin.readline().split())
    adj[a], adj[b] = adj[a]+1, adj[b]+1
    root_a, root_b = find(a), find(b)
    if root_a != root_b:
        parent[root_b] = root_a
    
for i in range(1, V+1):
    if adj[i] % 2:
        ret += 1
        
root = find(1)
for i in range(2, V+1):
    if find(i) != root:
        ret = -1
print('YES' if ret in [0, 2] else 'NO')
