import sys
from collections import deque

dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def sol(i, j):
    q = deque()
    q.append((i, j))
    maps_copy[i][j] = cnt

    while q:
        x, y = q.popleft()
        for dir in dirs:
            nx = x + dir[0]
            ny = y + dir[1]

            if 0 > nx or nx >= n or 0 > ny or ny >= n:
                continue

            if maps[x][y] == maps[nx][ny] and maps_copy[nx][ny] == 0:
                q.append((nx, ny))
                maps_copy[nx][ny] = 1
    # print(maps_copy)


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    maps = [list(map(str, sys.stdin.readline().strip()))for _ in range(n)]

    maps_copy = [[0] * n for _ in range(n)]
    cnt = 0
    for i in range(n):
        for j in range(n):
            if maps_copy[i][j] == 0:
                sol(i, j)
                cnt += 1
    print(cnt, end=' ')
    # print(cnt)



    for i in range(n):
        for j in range(n):
            if maps[i][j] == 'R':
                maps[i][j] = 'G'
    maps_copy = [[0] * n for _ in range(n)]

    cnt = 0
    for i in range(n):
        for j in range(n):
            if maps_copy[i][j] == 0:
                sol(i, j)
                cnt += 1
    print(cnt)
