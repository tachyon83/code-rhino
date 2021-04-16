from sys import stdin
import sys
sys.setrecursionlimit(1000000)

def dfs(r, c, cnt):

    for i in range(4):
        mapr = r + dr[i]
        mapc = c + dc[i]

        if mapr >= 0 and mapc >= 0 and mapr < N and mapc < M:
            if not visited[mapr][mapc] and area[mapr][mapc] == 1:
                visited[mapr][mapc] = True
                cnt = dfs(mapr, mapc, cnt + 1)

    return cnt

input = stdin.readline

N, M = map(int, input().split())

area = [list(input().strip()) for _ in range(N)]

visited = [[False] * M for _ in range(N)]

print(area)

dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]

cnt = 0
max_num = 0

for i in range(N):
    for j in range(M):
        if not visited[i][j] and area[i][j] == 1:
            visited[i][j] = True
            max_num = max(max_num, dfs(i, j, 1))
            cnt += 1

print(cnt)
print(max_num)

