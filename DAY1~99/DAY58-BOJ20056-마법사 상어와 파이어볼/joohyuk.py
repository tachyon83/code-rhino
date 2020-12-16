import sys
from collections import deque
si = sys.stdin.readline

sz = 50+1
massMap = [[[]for _ in range(sz)]for _ in range(sz)]
speedMap = [[[]for _ in range(sz)]for _ in range(sz)]
dirMap = [[[]for _ in range(sz)]for _ in range(sz)]
dr, dc = [-1, -1, 0, 1, 1, 1, 0, -1], [0, 1, 1, 1, 0, -1, -1, -1]
q = deque()


def manyBalls(n):
    global massMap, speedMap, dirMap, dr, dc, q

    for i in range(1, n+1):
        for j in range(1, n+1):
            num, sm, ss = len(massMap[i][j]), sum(
                massMap[i][j]), sum(speedMap[i][j])
            if num > 1 and sm >= 5:
                sampledir = (dirMap[i][j][0]) % 2
                flag = 0
                for e in dirMap[i][j]:
                    if e % 2 != sampledir:
                        flag = 1
                        break

                for k in range(4):
                    q.append([i, j, sm//5, ss//num, k*2+flag])
            elif num == 1:
                q.append([i, j, sm, ss, dirMap[i][j][0]])
            massMap[i][j], speedMap[i][j], dirMap[i][j] = [], [], []


def main():
    global massMap, speedMap, dirMap, dr, dc, q

    n, M, k = [int(e) for e in si().split()]

    while M:
        M -= 1
        q.append([int(e) for e in si().split()])

    while k:
        k -= 1
        qs = len(q)
        for _ in range(qs):
            r, c, m, s, d = q.popleft()
            nr, nc = (r+s*dr[d]) % n, (c+s*dc[d]) % n
            if not nr:
                nr = n
            if not nc:
                nc = n
            if 1 <= nr <= n and 1 <= nc <= n:
                massMap[nr][nc].append(m)
                speedMap[nr][nc].append(s)
                dirMap[nr][nc].append(d)
        manyBalls(n)

    t = 0
    while q:
        t += q.popleft()[2]
    print(t)


if __name__ == '__main__':
    main()
