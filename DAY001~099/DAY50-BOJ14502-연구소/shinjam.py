from collections import deque
from itertools import combinations


def bfs(lab, new_wall, virus, visited):
    queue = deque(list(virus))
    dx, dy = (1, 0, -1, 0), (0, 1, 0, -1)
    ret = 0
    while queue:
        cx, cy = queue.popleft()

        for d in range(4):
            ncx, ncy = cx + dx[d], cy + dy[d]
            if not 0 <= ncy < N or not 0 <= ncx < M:
                continue
            if lab[ncy][ncx] == 1 or (ncy, ncx) in new_wall:
                continue
            if (ncx, ncy) in visited:
                continue
            visited.add((ncx, ncy))
            ret += 1
            queue.append((ncx, ncy))
    return ret


N, M = map(int, input().split())
lab = [[0] * M for _ in range(N)]
zeros = set()
virus = set()
for n in range(N):
    for idx, val in enumerate(map(int, input().split())):
        lab[n][idx] = val
        if val == 2:
            virus.add((idx, n))
        if val == 0:
            zeros.add((n, idx))

# 벽 세우는 케이스
# 바이러스 퍼트리기
ret = float('inf')
for w1, w2, w3 in combinations(zeros, 3):
    cnt = 0
    new_wall = {w1, w2, w3}
    cnt += bfs(lab, new_wall, virus, set(virus))
    if cnt < ret:
        ret = cnt


print(len(zeros) - ret - 3)
