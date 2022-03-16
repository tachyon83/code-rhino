import sys
from collections import deque

dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def bfs(row, col):
    check = False
    visit = {(row, col)}
    q = deque([(row, col)])
    val, cnt = 0, 0

    while q:
        row, col = q.popleft()
        val += maps[row][col]
        cnt += 1
        for y, x in dir:
            ny = row + y
            nx = col + x
            # if ny < 0 or ny >= n or nx < 0 or nx >= n:
            #     continue
            if 0 <= ny < n and 0 <= nx < n and l <= abs(maps[row][col] - maps[ny][nx]) <= r and (ny, nx) not in visit:
                q.append((ny, nx))
                visit.add((ny, nx))
                check = True
    return val//cnt, visit, check


def sol():
    cnt = 0
    while True:
        is_move = False
        visited = set()
        tmp = []
        for i in range(n): # y
            for j in range(n): # x
                if (i, j) not in visited:
                    val, visit, flag = bfs(i, j)
                    if flag:
                        is_move = True
                    tmp.append((val, visit))
                    visited |= visit
        for (val, visit) in tmp:
            for y, x in visit:
                maps[y][x] = val
        if not is_move:
            return cnt
        cnt += 1

if __name__ == "__main__":
    n, l, r = list(map(int, sys.stdin.readline().split()))
    maps = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    print(sol())
