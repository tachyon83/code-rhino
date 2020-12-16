import sys

dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def findmin(s, p, d):
    global k, MIN

    if d > MIN:
        return

    if s == k:
        MIN = min(MIN, d)

    for i in range(k + 1):
        if not check[i]:
            check[i] = 1
            findmin(s + 1, i, d + graph[p][i])
            check[i] = 0


def bfs(y, x, n):
    global k, flag

    visit = [[0] * w for _ in range(h)]
    q = [(y, x)]
    visit[y][x] = 1
    chk = [0] * (k + 1)
    chk[n] = 1

    while q:
        y, x = q.pop(0)
        for dy, dx in dir:
            ny, nx = y + dy, x + dx
            if -1 >= ny or ny >= h or -1 >= nx or nx >= w:
                continue
            if not visit[ny][nx] and maps[ny][nx] != 'x':
                q.append((ny, nx))
                visit[ny][nx] = visit[y][x] + 1

                if maps[ny][nx] != -1:
                    t = maps[ny][nx]
                    graph[n][t] = visit[y][x]
                    graph[t][n] = visit[y][x]
                    chk[t] = 1
                    if sum(chk) == k + 1:
                        flag = 1
                        return


while True:
    w, h = list(map(int, sys.stdin.readline().split()))
    if not w and not h:
        break

    maps = [list((sys.stdin.readline().strip())) for _ in range(h)]

    k = 0
    position = []
    for i in range(h):
        for j in range(w):
            if maps[i][j] == '*':
                k += 1
                maps[i][j] = k
                position.append((i, j, k))

            elif maps[i][j] == 'o':
                maps[i][j] = 0
                position.insert(0, (i, j, 0))

            elif maps[i][j] == '.':
                maps[i][j] = -1

    graph = [[0] * (k + 1) for _ in range(k + 1)]

    flag = 0
    for i in range(k):
        flag = 0
        y, x, n = position[i][0], position[i][1], position[i][2]
        bfs(y, x, n)
        if not flag:
            break

    if not flag:
        print(-1)
        continue

    check = [0] * (k + 1)
    check[0] = 1
    MIN = 0x7fffffff
    findmin(0, 0, 0)
    print(MIN)
