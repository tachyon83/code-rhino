import sys
import copy

n = int(input())
grid = [[i for i in map(int, sys.stdin.readline().split())] for _ in range(n)]
gridcopy = copy.deepcopy(grid)
for k in range(n):
    for i in range(n):
        for j in range(n):
            if i == k or k == j: continue
            if grid[i][k] + grid[k][j] < grid[i][j]:
                print(-1)
                sys.exit()
            elif grid[i][k] + grid[k][j] == grid[i][j]:
                gridcopy[i][j] = 0
pathes = 0
for i in range(len(gridcopy)):
    for j in range(len(gridcopy)):
        pathes += gridcopy[i][j]
print(pathes//2)
