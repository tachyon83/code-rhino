import sys
from collections import deque

D = [[0, -1], [1, -1], [1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1]]

def sol(k):
    for _ in range(k):
        tmp = []
        for _ in range(len(q)):
            x, y = q.popleft()
            for _ in range(len(maps[x][y])):
                mi, si, di = maps[x][y].popleft()
                ny = (si * D[di][0] + y) % n
                nx = (si * D[di][1] + x) % n
                q.append([nx, ny])
                tmp.append([nx, ny, mi, si, di])

        for x, y, m, s, d in tmp:
            maps[x][y].append([m, s, d])

        for i in range(n):
            for j in range(n):
                if len(maps[i][j]) > 1:
                    nm, ns, odd, even, flag = 0, 0, 0, 0, 0
                    for idx, [m, s, d] in enumerate(maps[i][j]):
                        nm += m
                        ns += s
                        if idx == 0:
                            if d % 2 == 0:
                                even = 1
                            else:
                                odd = 1
                        else:
                            if even == 1 and d % 2 == 1:
                                flag = 1
                            elif odd == 1 and d % 2 == 0:
                                flag = 1
                    nm //= 5
                    ns //= len(maps[i][j])
                    maps[i][j] = deque()
                    if nm != 0:
                        for idx in range(4):
                            nd = 2 * idx if flag == 0 else 2 * idx +1
                            maps[i][j].append([nm,ns,nd])

    ans = 0
    for i in range(n):
        for j in range(n):
            if maps[i][j]:
                for m, s, d in maps[i][j]:
                    ans += m
    return ans

if __name__ == "__main__":
    n, m, k = list(map(int, sys.stdin.readline().split()))
    q = deque()
    maps = [[deque() for _ in range(n)] for _ in range(n)]
    for _ in range(m):
        ri, ci, mi, si, di = list(map(int, sys.stdin.readline().split()))
        q.append([ri-1, ci-1])
        maps[ri-1][ci-1].append((mi,si,di))

    print(sol(k))
