'''
https://chldkato.tistory.com/66

'''

from collections import deque
from itertools import permutations
import sys

input = sys.stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(x, y):
    q = deque()
    c = [[0]*w for _ in range(h)]
    q.append([x, y])
    c[x][y] = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < h and 0 <= ny < w:
                if a[nx][ny] != 'x' and not c[nx][ny]:
                    c[nx][ny] = c[x][y] + 1
                    q.append([nx, ny])
    return c

while True:
    w, h = map(int, input().split())
    if not w and not h:
        break

    a, d = [], []
    for i in range(h):
        row = list(input().strip())
        a.append(row)
        for j, k in enumerate(row):
            if k == 'o':
                sx, sy = i, j
            elif k == '*':
                d.append([i, j])

    r2d, flag = [], 0
    c = bfs(sx, sy)
    for i, j in d:
        if not c[i][j]:
            flag = 1
            break
        r2d.append(c[i][j]-1)
    if flag:
        print(-1)
        continue

    d2d = [[0]*len(d) for _ in range(len(d))]
    for i in range(len(d)-1):
        c = bfs(d[i][0], d[i][1])
        for j in range(i+1, len(d)):
            d2d[i][j] = c[d[j][0]][d[j][1]]-1
            d2d[j][i] = d2d[i][j]

    p = list(permutations([i for i in range(len(d2d))]))
    ans = sys.maxsize
    for i in p:
        dist = 0
        dist += r2d[i[0]]
        nfrom = i[0]
        for j in range(1, len(i)):
            nto = i[j]
            dist += d2d[nfrom][nto]
            nfrom = nto
        ans = min(ans, dist)
    print(ans)
