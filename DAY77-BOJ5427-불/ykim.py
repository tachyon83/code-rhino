from collections import deque
import sys

input = sys.stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(x, y):
    q.append([x, y])
    c[x][y] = 1
    while q:
        qlen = len(q)
        while qlen:
            x, y = q.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < h and 0 <= ny < w:
                    if a[nx][ny] == '.' and c[nx][ny] == 0:
                        c[nx][ny] = c[x][y] + 1
                        q.append([nx, ny])
                elif nx < 0 or ny < 0 or nx >= h or ny >= w:
                    print(c[x][y])
                    return
            qlen -= 1
        fire()

    print("IMPOSSIBLE")
    return

def fire():
    qlen = len(fq)
    while qlen:
        x, y = fq.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < h and 0 <= ny < w:
                if a[nx][ny] == '.':
                    a[nx][ny] = '*'
                    fq.append([nx, ny])
        qlen -= 1

tc = int(input())
while tc:
    w, h = map(int, input().split())
    a = [list(map(str, input().strip())) for _ in range(h)]
    fq, q = deque(), deque()
    c = [[0]*w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            if a[i][j] == '@':
                sx = i; sy = j
                a[i][j] = '.'
            if a[i][j] == '*':
                fq.append([i, j])
    fire()
    bfs(sx, sy)
    tc -= 1
