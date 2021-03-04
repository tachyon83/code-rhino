import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline


N, M = map(int, input().split())

parent = list(range(N + 1))
rank = [0] * (N + 1)

def find(x):
    if x == parent[x]:
        return x
    parent[x] = find(parent[x])
    return parent[x]

def union(u, v):
    u = find(u)
    v = find(v)
    if u == v:
        return
    if rank[u] > rank[v]:
        u, v = v, u
    parent[u] = v
    if rank[u] == rank[v]:
        rank[v] += 1

for _ in range(M):
    i, j = map(int, input().split())
    union(i, j)

s = set()
for i in range(1, N + 1):
    s.add(find(i))
    
print(len(s))