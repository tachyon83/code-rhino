import sys
from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def sol():
    day = 1
    while q:
        for _ in range(len(f_q)):
            x, y = f_q.popleft()
            for i in range(4):
                n_y = y + dy[i]
                n_x = x + dx[i]
                if n_x < 0 or n_y < 0 or n_x >= h or n_y >= w:
                    continue
                if maps[n_x][n_y] == '.':
                    maps[n_x][n_y] = '*'
                    f_q.append((n_x, n_y))

        for t in range(len(q)):
            x, y = q.popleft()
            for i in range(4):
                n_y = y + dy[i]
                n_x = x + dx[i]
                if n_x < 0 or n_y < 0 or n_x >= h or n_y >= w:
                    return day
                if maps[n_x][n_y] == '.':
                    maps[n_x][n_y] = '@'
                    q.append((n_x, n_y))
        day += 1
    return 'IMPOSSIBLE'

if __name__ == "__main__":
    case = int(sys.stdin.readline())
    for i in range(case):
        w, h = map(int, sys.stdin.readline().split())
        maps = [list(sys.stdin.readline().rstrip()) for _ in range(h)]
        f_q, q = deque(), deque()
        for i in range(h):
            for j in range(w):
                if maps[i][j] == '@':
                    q.append([i, j])
                elif maps[i][j] == '*':
                    f_q.append([i, j])

        print(sol())
