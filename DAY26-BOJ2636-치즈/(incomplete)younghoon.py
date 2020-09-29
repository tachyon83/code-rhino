#나중에 시간날때 BFS로 다시 구현 하겠습니다


import copy
h, w = map(int, input().split())
grid = list(list(map(int, input().split())) for _ in range(h))
# 동서남북
dx = [0,0,1,-1]
dy = [1,-1,0,0]
gridcopy = copy.deepcopy(grid)
visited = [[0 for i in range(w)] for j in range(h)]

def dfs(x,y):
    visited[x][y] = 1
    if x == h - 1 and y == w -1:
        return
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if nx < 0 or nx >= h or ny < 0 or ny >= w or visited[nx][ny] == 1:
            continue
        else:
            if grid[nx][ny] == 1:
                gridcopy[nx][ny] = 'c'
                continue
            dfs(nx,ny)

def all_zero():
    for x in range(h):
        for y in range(w):
            if grid[x][y] != 0:
                return False
    return True
def c_to_zero():
    for x in range(h):
        for y in range(w):
            if gridcopy[x][y] == 'c':
                gridcopy[x][y] = 0
def cheese_count(prev):
    count = 0
    for x in range(h):
        for y in range(w):
            if prev[x][y] == 1:
                count += 1
    return count
def print_grid(grid):
    for x in range(h):
        for y in range(w):
            print(grid[x][y], end= " ")
        print( )
    print()


def reset_visited():
    for x in range(h):
        for y in range(w):
            visited[x][y] = 0

if all_zero() == True:
    print(0)
    print(0)
    sys.exit(-1)

melting_time = 0
while all_zero() == False:
    prev = copy.deepcopy(grid)
    reset_visited()
    dfs(0,0)
    melting_time += 1
    c_to_zero()
    grid = copy.deepcopy(gridcopy)

print(melting_time)
print(cheese_count(prev))

