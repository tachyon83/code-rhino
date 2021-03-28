import sys
from collections import deque

def solution(r,c):
    dist[r][c] = 0
    q = deque()
    q.append([r,c])
    while q:
        r, c = q.popleft()
        for i in range(4):
            new_r = r + dr[i]
            new_c = c + dc[i]
            if new_r >=0 and new_r < n and new_c >=0 and new_c <m:
                if dist[new_r][new_c] == -1:
                    if maze[new_r][new_c] == '0':
                        q.appendleft([new_r, new_c])
                        dist[new_r][new_c] = dist[r][c]
                    elif maze[new_r][new_c] == '1':
                        q.append([new_r,new_c])
                        dist[new_r][new_c] = dist[r][c] + 1

m,n = map(int, sys.stdin.readline().split())
dr = [0, 0, 1, -1]
dc = [1, -1, 0, 0]
dist = [[-1 for _ in range(m)] for _ in range(n)]
maze = []
for _ in range(n):
    maze.append(sys.stdin.readline().strip())
ans = 10000
solution(0, 0)
print(dist[n-1][m-1])
