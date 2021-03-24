import sys
import heapq

def dijkstra(start):
    q = []
    res = [sys.maxsize for _ in range(n + 1)]
    res[start] = 0
    heapq.heappush(q, [start, 0])
    prev = [0 for _ in range(n)]
    while q:
        v, d = heapq.heappop(q)
        if res[v] >= d:
            for (i, w) in graph[v]:
                if res[i] > res[v] + w:
                    res[i] = res[v] + w
                    prev[i-1] = v
                    heapq.heappush(q, [i, res[v] + w])
    return prev

n, m = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b, t = map(int, sys.stdin.readline().split())
    graph[a].append((b,t))
    graph[b].append((a,t))
for i in range(1, n+1):
    prev = dijkstra(i)
    for j in range(1, n+1):
        if j == i:
            print('-', end=' ')
        elif prev[j - 1] == i:
            print(j, end=' ')
        else:
            idx = j
            while 1:
                if prev[idx - 1] == i:
                    print(idx, end=' ')
                    break
                else:
                    idx = prev[idx - 1]
    print()
