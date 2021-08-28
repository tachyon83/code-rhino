import sys
from collections import deque
si = sys.stdin.readline

t = int(si())
for n in range(t):
    a, b, c = si().split()
    asz, bsz, q = len(a), len(b), deque()
    vis = [[False for _ in range(bsz+1)]for _ in range(asz+1)]

    vis[0][0] = True
    q.append([0, 0, 0])
    while q:
        i, j, k = q.popleft()
        if i < asz and k < (asz+bsz) and c[k] == a[i] and not vis[i+1][j]:
            vis[i+1][j] = True
            q.append([i+1, j, k+1])
        if j < bsz and k < (asz+bsz) and c[k] == b[j] and not vis[i][j+1]:
            vis[i][j+1] = True
            q.append([i, j+1, k+1])

    print('Data set %d:' % (n+1), end=' ')
    print('yes' if vis[asz][bsz] else 'no')
