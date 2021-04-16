import sys
import heapq

def dijkstra(r,c):
    dist[r][c] = int(cave[r][c])
    q = []
    heapq.heappush(q, [r, c, int(cave[r][c])])
    while q:
        r, c, d = heapq.heappop(q)
        for i in range(4):
            new_r = r + dr[i]
            new_c = c + dc[i]
            if 0 <= new_r < n and 0 <= new_c < n:
                d_tmp = d + int(cave[new_r][new_c])
                if d_tmp < dist[new_r][new_c]:
                    dist[new_r][new_c] = d_tmp
                    heapq.heappush(q, [new_r, new_c, d_tmp])
cnt = 1
while True:
    n = int(sys.stdin.readline())
    if n == 0:
        break
    cave = []
    for _ in range(n):
        cave.append(sys.stdin.readline().split())
    dist = [[sys.maxsize for _ in range(n)] for _ in range(n)]
    dr = [0, 0, 1, -1]
    dc = [1, -1, 0, 0]
    dijkstra(0, 0)
    print(f'Problem {cnt}: {dist[n-1][n-1]}')
    cnt += 1
