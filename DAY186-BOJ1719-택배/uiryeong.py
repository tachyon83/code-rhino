from heapq import heappush, heappop
import sys
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def dijkstra(start):
    heap = []
    heappush(heap, [0, start])
    dp = [100000000 for i in range(n + 1)]
    dp[start] = 0
    while heap:
        w, nu = heappop(heap)
        for ne, nw in s[nu]:
            wei = nw + w
            if dp[ne] > wei:
                dp[ne] = wei
                heappush(heap, [wei, ne])
                d[ne - 1][start - 1] = nu
                
n, m = map(int, input().split())
s = [[] for i in range(n + 1)]
d = [[0] * n for i in range(n)]

for i in range(m):
    a, b, c = map(int, input().split())
    s[a].append([b, c])
    s[b].append([a, c])

for i in range(1, n + 1):
    dijkstra(i)

for i in range(n):
    for j in range(n):
        if i == j:
            print("-", end=" ")
        else:
            print(d[i][j], end=" ")
