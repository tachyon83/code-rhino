"""
런타임에러...
"""

import sys
from collections import deque

dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
w, b = 0, 0
def sol(i, j, a):
    cnt = 1
    q = deque()
    q.append((i, j))
    ch[i][j] = True
    while q:
        x, y = q.popleft()
        for dir in dirs:
            nx, ny = x+dir[0], y+dir[1]
            if 0 <= nx < n and 0 <= ny < m:
                if lst[nx][ny] == a and ch[nx][ny] == False:
                    q.append((nx, ny))
                    ch[nx][ny] = True
                    cnt += 1

    return cnt

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    lst = [list(sys.stdin.readline().strip()) for _ in range(n)]
    ch = [[False] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if ch[i][j] == True:
                continue
            k = sol(i, j, lst[i][j])
            if lst[i][j] == 'W':
                w += k*k
            else:
                b += k*k
    print(w, b)
