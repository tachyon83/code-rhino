import copy
input = __import__('sys').stdin.readline

def move(x, y):
    yield x + 1, y
    yield x - 1, y
    yield x, y + 1
    yield x, y - 1

def melt():
    tmp = copy.deepcopy(sea)

    for i in range(N):
        for j in range(M):
            if sea[i][j] == 0:
                continue
            cnt = 0
            for cx, cy in move(i, j):
                if cx < 0 or cx >= N or cy < 0 or cy >= M:
                    continue
                if sea[cx][cy] == 0:
                    cnt += 1

            tmp[i][j] = max(sea[i][j] - cnt, 0)

    return tmp

def findMass():
    messCnt = 0
    visited = [[0] * M for _ in range(N)]
    q = []

    for i in range(N):
        for j in range(M):
            if sea[i][j] == 0 or visited[i][j]:
                continue

            messCnt += 1
            q.append((i, j))
            visited[i][j] = 1

            while q:
                x, y = q.pop()
                for cx, cy in move(x, y):
                    if cx < 0 or cx >= N or cy < 0 or cy >= M or visited[cx][cy]:
                        continue
                    if sea[cx][cy] != 0:
                        visited[cx][cy] = 1
                        q.append((cx, cy))

    return messCnt


N, M = map(int, input().split())
sea = [list(map(int, input().split())) for _ in range(N)]
iceburg = []
year = 0

while True:
    massCnt = findMass()
    if massCnt == 0:
        print(0)
        break
    elif massCnt > 1:
        print(year)
        break
    sea = melt()
    year += 1
