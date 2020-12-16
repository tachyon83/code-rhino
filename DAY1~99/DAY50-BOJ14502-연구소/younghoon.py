import sys
import copy
#sys.stdin = open('input.txt', 'r')

N, M = map(int, sys.stdin.readline().split())

virus_map = []
for _ in range(N):
    virus_map.append(list(map(int, sys.stdin.readline().split())))


# 동서남북
dx = [1,-1,0,0]
dy = [0,0,1,-1]
max_safe = 0

def safe_count(temp_map):
    safe_count = 0
    for i in range(N):
        for j in range(M):
            if temp_map[i][j] == 0:
                safe_count+=1
    return safe_count

def bfs():
    global max_safe
    temp_map = copy.deepcopy(virus_map)
    virus = []
    for i in range(N):
        for j in range(M):
            if virus_map[i][j] == 2:
                virus.append([i, j])
    while virus:
        x,y = virus.pop()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<N and 0<=ny<M and temp_map[nx][ny] == 0:
                temp_map[nx][ny] = 2
                virus.append([nx,ny])
    max_safe = max(max_safe, safe_count(temp_map))

def wall(count):
    if count == 3:
        bfs()
        return
    for i in range(N):
        for j in range(M):
            if virus_map[i][j] == 0:
                virus_map[i][j] = 1
                wall(count + 1)
                virus_map[i][j] = 0

wall(0)
print(max_safe)
