from collections import deque
from itertools import combinations
from copy import deepcopy


def bfs(x, y):
    global tmp_lab
    queue = deque([(x, y)])
    dx, dy = (1, 0, -1, 0), (0, 1, 0, -1)
    ret = 0
    while queue:
        cx, cy = queue.popleft()

        for d in range(4):
            ncx, ncy = cx + dx[d], cy + dy[d]
            if not 0 <= ncy < N or not 0 <= ncx < M:
                continue
            if tmp_lab[ncy][ncx] == 1 or tmp_lab[ncy][ncx] == 2:
                continue
            tmp_lab[ncy][ncx] = 2
            ret += 1
            queue.append((ncx, ncy))
    return ret


N, M = map(int, input().split())
lab = [[0] * M for _ in range(N)]
zero = 0
virus = []
for n in range(N):
    for idx, val in enumerate(map(int, input().split())):
        lab[n][idx] = val
        if val == 2:
            virus.append((idx, n))
        if val == 0:
            zero += 1

ret = float('inf')
for w1, w2, w3 in combinations(range(N * M), 3):
    tmp_lab = deepcopy(lab)
    wy1, wx1 = divmod(w1, M)
    wy2, wx2 = divmod(w2, M)
    wy3, wx3 = divmod(w3, M)
    cnt = 0
    if not any([lab[wy1][wx1], lab[wy2][wx2], lab[wy3][wx3]]):
        tmp_lab[wy1][wx1] = 1
        tmp_lab[wy2][wx2] = 1
        tmp_lab[wy3][wx3] = 1
        for v in virus:
            cnt += bfs(*v)
        if cnt < ret:
            ret = cnt

print(zero - ret - 3)
