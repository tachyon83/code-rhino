import sys
from collections import deque

dx, dy = [-1, 0, 1, 0], [0, -1, 0, 1]

def sol():
  ans = 0
  for i in range(n):
    for j in range(m):
      if maps[i][j] == 1 and ch[i][j] == False:
        cnt = 0
        q = deque()
        q.append((i, j))
        ch[i][j] = True
        cnt += 1
        while q:
          x, y = q.popleft()
          for p in range(4):
            nx = x + dx[p]
            ny = y + dy[p]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
              continue
            if maps[nx][ny] == 1 and ch[nx][ny] == False:
              ch[nx][ny] = True
              q.append((nx, ny))
        ans += cnt
  return ans

if __name__ == "__main__":
   t = int(sys.stdin.readline())
   for _ in range(t):
    m, n, k = list(map(int, sys.stdin.readline().split()))
    maps = [[0] * m for _ in range(n)]
    ch = [[False] * m for _ in range(n)]
    for i in range(k):
      x, y = list(map(int, sys.stdin.readline().split()))
      maps[y][x] = 1
    print(sol())
