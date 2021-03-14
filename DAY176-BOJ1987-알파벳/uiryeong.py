from sys import stdin
import sys
sys.setrecursionlimit(1000000)

input = stdin.readline

N, M = map(int, input().split())

area = [list(input().strip()) for _ in range(N)]

# visited = [[False] * M for _ in range(N)]
visited = [False] * 26

dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]

ans = 0

def dfs(r, c, z):
    global ans
    ans = max(ans, z)
    
    for i in range(4):
        mapr = r + dr[i]
        mapc = c + dc[i]

        if mapr < 0 or mapc < 0 or mapr >= N or mapc >= M:
            continue

        c = ord(area[mapr][mapc]) - ord('A')

        if not visited[c]:
            visited[c] = True
            dfs(mapr, mapc, z+1)
            visited[c] = False


visited[ord(area[0][0]) - ord('A')] = True

dfs(0, 0, 0)

print(ans)
