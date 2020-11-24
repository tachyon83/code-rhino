def solution(n, m, fire, human):
    def is_out_bound(y, x):
        return not (0 <= y < n and 0 <= x < m)

    cnt = 0
    dy = (1, -1, 0, 0)
    dx = (0, 0, 1, -1)
    while human:

        for _ in range(len(human)):
            y, x = human.popleft()
            if mat[y][x] == "*":
                continue
            for k in range(4):
                yy, xx = y+dy[k], x+dx[k]
                if is_out_bound(yy, xx):
                    res = cnt + 1
                    return res
                    
                if mat[yy][xx] in {"@", "*",  "#"}:
                    continue
                if mat[yy][xx] == ".":
                    mat[yy][xx] = "@"
                    human.append((yy, xx))

        for _ in range(len(fire)):
            fy, fx = fire.popleft()
            for k in range(4):
                fyy, fxx = fy+dy[k], fx+dx[k]
                if is_out_bound(fyy,fxx) or mat[fyy][fxx] in {"#", "*"}:
                    continue
                if mat[fyy][fxx] in {"." , "@"}:
                    mat[fyy][fxx] = "*"
                    fire.append((fyy, fxx))
        cnt += 1
    return "IMPOSSIBLE"


if __name__ == "__main__":
    import sys
    from collections import deque
    input = sys.stdin.readline

    for t in range(int(input())):
        m, n = map(int,input().split())
        mat = [list(input()) for _ in range(n)]

        fire = deque([])
        for i in range(n):
            for j in range(m):
                if mat[i][j] == "@":
                    human = deque([(i, j)])
                if mat[i][j] == "*":
                    fire.append((i, j))

        print(solution(n,m,fire,human))

