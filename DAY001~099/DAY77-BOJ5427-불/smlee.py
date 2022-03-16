from collections import deque
import sys
input = sys.stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
def bfs():
    global q, f
    while q:
        temp = deque()
        while q:
            x, y = q.popleft()
            if (x == h - 1 or y == w - 1 or x == 0 or y == 0) and s[x][y] != "*": return s[x][y]
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < h and 0 <= ny < w and s[nx][ny] == "." and s[x][y] != "*":
                    s[nx][ny] = s[x][y] + 1
                    temp.append([nx, ny])
        q = temp
        temp = deque()
        while f:
            x, y = f.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < h and 0 <= ny < w and visit[nx][ny] == 0 and s[nx][ny] != "#":
                    s[nx][ny] = "*"
                    visit[nx][ny] = 1
                    temp.append([nx, ny])
        f = temp
t = int(input())
for i in range(t):
    w, h = map(int, input().split())
    s, f, q = [], deque(), deque()
    visit = [[0] * w for i in range(h)]
    for j in range(h):
        a = list(input().strip())
        s.append(a)
        for k in range(w):
            if a[k] == "@":
                s[j][k] = 0
                q.append([j, k])
            elif a[k] == "*":
                f.append([j, k])
                visit[j][k] = 1
    result = bfs()
    print(result + 1 if result != None else "IMPOSSIBLE")
