import sys
sys.setrecursionlimit(100001)
dirs = [(1, 0),(0, 1),(-1, 0),(0, -1)]

def sol(x, y):
    if check[x][y]: return check[x][y]
    check[x][y] = 1

    for dir in dirs:
        nx = x + dir[0]
        ny = y + dir[1]

        if 0 <= nx < n and 0 <= ny < n:
            if maps[nx][ny] > maps[x][y]:
                check[x][y] = max(check[x][y], sol(nx, ny) + 1)
    return check[x][y]

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    maps = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    check = [[0] * n for _ in range(n)]
    res = 0
    for i in range(n):
        for j in range(n):
            res = max(res, sol(i, j))

    print (res)
