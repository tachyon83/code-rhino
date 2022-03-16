import sys
from collections import deque

dx = [0, 0, 1, -1]
dy = [-1, 1, 0, 0]

def bfs_(m, n, maps):
    cnt = -1
    while q:
        cnt += 1
        for _ in range(len(q)):
            x, y = q.popleft()
            for i in range(4):
                a = x + dx[i]
                b = y + dy[i]
                if (0 <= a < n) and (0 <= b < m) and (maps[a][b] == 0):
                    maps[a][b] = maps[x][y] + 1
                    q.append([a, b])
    for i in maps:
        if 0 in i:
            return -1
    return cnt

if __name__ == "__main__":
    m, n = map(int, sys.stdin.readline().split())
    maps = []
    q = deque()
    for i in range(n):
        row = list(map(int, sys.stdin.readline().split()))
        for j in range(m):
            if row[j] == 1:
                q.append([i, j])
        maps.append(row)

    print(bfs_(m, n, maps))
