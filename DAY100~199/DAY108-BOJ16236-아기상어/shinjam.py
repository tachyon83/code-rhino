N = int(input())
BOARD = list()
start = tuple()
for i in range(N):
    BOARD.append(list(map(int, input().split())))
    for j in range(N):
        if BOARD[i][j] == 9:
            start = (j, i)        
            
from collections import deque
from heapq import heappush, heappop
dx, dy = (1, 0, -1, 0), (0, 1, 0, -1)

def bfs(x, y):
    visited = list([0]*N for _ in range(N))
    visited[y][x]= 1
    size, eat = 2, 0
    queue = [(0, y, x)] # 시간, col, row, 크기, 먹이
    ans = 0
    while queue:
        time, y, x = heappop(queue)
        print(time, y, x, size, eat)
        ans = time
        for v in range(4):
            nx, ny = x+dx[v], y+dy[v]
            new_eat, new_size = eat, size
            if not (0<=nx<N and 0<=ny<N):
                continue
            if visited[ny][nx]: # 이미 방문 했을 때
                continue
            if BOARD[ny][nx] > size: # 물고기 크기가 더클 때
                continue
            elif BOARD[ny][nx] and BOARD[ny][nx] < size: # 물고기 크기가 작을 때
                print("!!", ny, nx, BOARD[ny][nx], size)
                BOARD[ny][nx] = 0
                visited = list([0]*N for _ in range(N))
                visited[ny][nx] = 1
                eat += 1
                print("  ", new_eat, size)
                if eat == size: # 먹이 갯수 채울 때
                    size += 1
                    eat = 0
            visited[ny][nx] = 1
            heappush(queue, (time+1, ny, nx))
    return ans
bfs(*start)
