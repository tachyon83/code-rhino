from collections import defaultdict
import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline


N = int(input())
graph = defaultdict(list)
for _ in range(N - 1):
    i, j = map(int, input().split())
    graph[i].append(j)
    graph[j].append(i)

parent = [0] * (N + 1)
seen = set()

def dfs(node, p):
    parent[node] = p
    seen.add(node)
    for nei in graph[node]:
        if nei not in seen:
            dfs(nei, node)

dfs(1, 0)
            
for i in parent[2:]:
    print(i)