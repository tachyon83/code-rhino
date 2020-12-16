import sys
sys.setrecursionlimit(100000)

dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]
max_ = 2001

def dfs_(y, x):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if ny < 0 or nx < 0 or nx >= max_ or ny >= max_:
            continue
        if maps[ny][nx] == 2 or maps[ny][nx] == 0:
            continue
        maps[ny][nx] = 2
        dfs_(ny, nx)

def sol():
    cnt = 0
    for i in range(max_):
        for j in range(max_):
            if maps[i][j] == 1:
                cnt +=1
                maps[i][j] = 2
                dfs_(i, j)
    if maps[1000][1000] == 2:
        cnt -= 1

    print(cnt)

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    maps = [[0]*max_ for _ in range(max_)]
    for _ in range(n):
        x1, y1, x2, y2 = list(map(int, sys.stdin.readline().split()))
        x1 = (x1 + 500)*2
        y1 = (y1 + 500)*2
        x2 = (x2 + 500)*2
        y2 = (y2 + 500)*2

        for i in range(x1, x2+1):
            maps[y1][i] = 1
            maps[y2][i] = 1

        for i in range(y1, y2+1):
            maps[i][x1] = 1
            maps[i][x2] = 1
    sol()
