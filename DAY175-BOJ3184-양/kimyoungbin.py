import sys
from collections import deque


def bfs(start_r, start_c):
    queue = deque()
    queue.append((start_r, start_c))
    sheep = 0
    wolf = 0
    if yard[start_r][start_c] == 'o':
        sheep += 1
    elif yard[start_r][start_c] == 'v':
        wolf += 1
    while queue:
        r, c = queue.pop()
        for dr, dc in dirs:
            new_r = r + dr
            new_c = c + dc
            if 0 <= new_r < R and 0 <= new_c < C:
                if visit[new_r][new_c] == 0 and yard[new_r][new_c] != '#':
                    queue.append((new_r, new_c))
                    visit[new_r][new_c] = 1
                    if yard[new_r][new_c] == 'o':
                        sheep += 1
                    elif yard[new_r][new_c] == 'v':
                        wolf += 1
    return sheep, wolf


if __name__ == "__main__":
    dirs = [(0, -1), (0, 1), (-1, 0), (1, 0)]
    R, C = map(int, sys.stdin.readline().split())
    yard = [list(map(str, sys.stdin.readline().strip())) for _ in range(R)]
    visit = [[0 for _ in range(C)] for _ in range(R)]
    ans_s = 0
    ans_w = 0
    for i in range(R):
        for j in range(C):
            if yard[i][j] != '#' and visit[i][j] == 0:
                visit[i][j] = 1
                s, w = bfs(i, j)
                if s > w:
                    ans_s += s
                else:
                    ans_w += w
    print(str(ans_s) + ' ' + str(ans_w))
