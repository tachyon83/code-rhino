from sys import stdin
import sys
sys.setrecursionlimit(1000000)

input = stdin.readline

N = int(input())

area = [list(input().strip()) for _ in range(N)]

visited = [[False] * N for _ in range(N)]


dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]

def dfs(r, c):
    if area[r][c] == '0':
        return 0
    if visited[r][c]:
        return 0
    visited[r][c] = True
    ret = 1
    for i in range(4):
        mapr = r + dr[i]
        mapc = c + dc[i]

        if mapr >= 0 and mapc >= 0 and mapr < N and mapc < N:
            # if not visited[mapr][mapc] and area[mapr][mapc] == 1:
            ret += dfs(mapr, mapc)

    return ret

cnt = 0
max_num = 0
area_sizes = []

for i in range(N):
    for j in range(N):
        if not visited[i][j] and area[i][j] == '1':
            area_size = dfs(i, j)
            area_sizes.append(area_size)
            cnt += 1

print(cnt)
for area in sorted(area_sizes):
    print(area)
