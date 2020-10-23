from collections import deque
import sys
si = sys.stdin.readline
def solution(m, n, mat):
    dy = [0, 1, 0, -1]
    dx = [1, 0, -1, 0]
    zero_cnt = 0
    visited =[[0] * m for _ in range(n)]
    dq = deque([])
    for i in range(n):
        for j in range(m):
            if mat[i][j] == 0:
                zero_cnt += 1
            elif mat[i][j] == 1:
                visited[i][j] = 1
                dq.append((i, j, 0))
    days = 0
    res = None
    while dq:
        y, x, cnt = dq.popleft()
        res = cnt
        for k in range(4):
            ny, nx = y+dy[k], x+dx[k]
            if not (0<=ny<n and 0<=nx<m) or visited[ny][nx] or mat[ny][nx] == -1:
                continue
            zero_cnt -= 1
            dq.append((ny, nx, cnt+1))
            visited[ny][nx] = 1
    
    if zero_cnt:
        return -1
    return res    


if __name__ == "__main__":
    m, n = map(int, si().split())
    mat = [[*map(int, si().split())] for _ in range(n)]
    print(solution(m, n, mat))

