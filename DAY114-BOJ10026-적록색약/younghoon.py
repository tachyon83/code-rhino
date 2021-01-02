import sys
sys.setrecursionlimit(10000)


N = int(sys.stdin.readline()) 
grid = [list(sys.stdin.readline()) for _ in range(N)]


dx = [1, -1, 0, 0] 
dy = [0, 0, 1, -1]

def dfs(x,y,color):
    visited.append((x,y))
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if(0 <= nx < N) and (0 <= ny < N) and ((nx, ny) not in visited):
            if color == 0 and grid[nx][ny] == grid[x][y]:
                dfs(nx,ny,0)
            elif color == 1 and grid[nx][ny] == grid[x][y]:
                dfs(nx,ny,1)
                
visited = []
count1 = 0
for i in range(N):
    for j in range(N):
        if (i,j) not in visited:
            dfs(i,j,0)
            count1+=1

for i in range(N):
    for j in range(N):
        if grid[i][j] == "G":
            grid[i][j] = "R"

visited = []
count2 = 0
for i in range(N):
    for j in range(N):
        if (i,j) not in visited:
            dfs(i,j,1)
            count2+=1
            
print(count1,count2)
            
        

