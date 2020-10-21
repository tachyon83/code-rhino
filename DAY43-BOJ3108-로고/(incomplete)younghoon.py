import sys
#sys.stdin = open("input.txt", "r")
N = int(sys.stdin.readline())
grid = [[0] * 2001 for _ in range(2001)]

#(동, 서, 남, 북)
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

for _ in range(N):
    x1,y1,x2,y2 = map(lambda x:(x+500)*2, map(int, sys.stdin.readline().split()))
    for i in range(y1, y2 + 1):
        grid[x1][i] = 1
        grid[x2][i] = 1
    for i in range(x1, x2 + 1):
        grid[i][y1] = 1
        grid[i][y2] = 1

def dfs(x,y):
    if 0<=x<2001 and 0<=y<2001 and grid[x][y] == 1:
        grid[x][y] = 2
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            dfs(nx,ny)
    else:
        return

count = 0
for i in range(2001):
    for j in range(2001):
        if grid[i][j] == 1:
            dfs(i,j)
            count += 1

if grid[1000][1000] == 2:
    count -= 1
print(count)




