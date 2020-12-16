from collections import deque
import sys

input = sys.stdin.readline
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

n, m, k = map(int, input().split())
q = deque()
a = [[deque() for _ in range(n)] for _ in range(n)]
for _ in range(m):
    r, c, m, s, d = map(int, input().split())
    a[r-1][c-1].append([m, s, d])
    q.append([r-1, c-1])

for _ in range(k):
    temp = []
    qlen = len(q)
    for _ in range(qlen):
        x, y = q.popleft()
        for _ in range(len(a[x][y])):
            m, s, d = a[x][y].popleft()
            nx = (s * dx[d] + x) % n
            ny = (s * dy[d] + y) % n
            q.append([nx, ny])
            temp.append([nx, ny, m, s, d])

    for x, y, m, s, d in temp:
        a[x][y].append([m, s, d])

    for i in range(n):
        for j in range(n):
            if len(a[i][j]) > 1:
                nm, ns, odd, even, flag = 0, 0, 0, 0, 0
                for idx, [m, s, d] in enumerate(a[i][j]):
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
                ns //= len(a[i][j])
                a[i][j] = deque()
                if nm != 0:
                    for idx in range(4):
                        nd = 2 * idx if flag == 0 else 2 * idx + 1
                        a[i][j].append([nm, ns, nd])

ans = 0
for i in range(n):
    for j in range(n):
        if a[i][j]:
            for m, s, d in a[i][j]:
                ans += m
print(ans)
