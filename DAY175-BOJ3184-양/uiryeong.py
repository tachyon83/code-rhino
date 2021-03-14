from sys import stdin
import sys
sys.setrecursionlimit(1000000)

input = stdin.readline

N, M = map(int, input().split())

area = [list(input().strip()) for _ in range(N)]

visited = [[False] * M for _ in range(N)]

dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]

totalWolf = 0
totalSheep = 0

curWolf = 0
curSheep = 0

for item in area:
    for elem in item:
        if elem == 'v':
            totalWolf += 1
        elif elem == 'o':
            totalSheep += 1

def dfs(r, c):
    global curWolf, curSheep
    visited[r][c] = True

    if area[r][c] == 'v':
        curWolf += 1
    elif area[r][c] == 'o':
        curSheep += 1
    for i in range(4):
        mapr = r + dr[i]
        mapc = c + dc[i]

        if mapr < 0 or mapc < 0 or mapr >= N or mapc >= M:
            continue

        if not visited[mapr][mapc] and area[mapr][mapc] != '#':
            dfs(mapr, mapc)
        # Fail case
        # if mapr >= 0 and mapc >= 0 and mapr < N and mapc < N:
        #     if not visited[mapr][mapc]:
        #         if area[mapr][mapc] != '#':
        #             dfs(mapr, mapc)


for i in range(N):
    for j in range(M):

        if area[i][j] == '#':
            continue
        curWolf = 0
        curSheep = 0

        if area[i][j] != '#' and not visited[i][j]:
    
            dfs(i, j)
        
        if curWolf >= curSheep:
            totalSheep -= curSheep
        elif curWolf < curSheep:
            totalWolf -= curWolf
        
print(totalSheep, totalWolf)
