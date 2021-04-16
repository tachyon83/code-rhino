def check(x, y):
    types = ['rrr','ddd','dru','ddr','urr','rdd','rru','ruu','drr','uur','rrd','drd','rur','dld','rdr']
    types_b = ['ldr', 'lud', 'lur', 'udr']
    vector = {
        'r': (1, 0),
        'l': (-1, 0),
        'u': (0, -1),
        'd': (0, 1)
    }
    
    ret = 0
    for t in types:
        cur = BOARD[y][x]
        tx, ty = x, y
        for v in t:
            nx, ny = tx+vector[v][0], ty+vector[v][1]
            if 0<=nx<M and 0<=ny<N:
                cur += BOARD[ny][nx]
                tx, ty = nx, ny
        ret = max(cur, ret)
    for t in types_b:
        cur = BOARD[y][x]
        for v in t:
            nx, ny = x+vector[v][0], y+vector[v][1]
            if 0<=nx<M and 0<=ny<N:
                cur += BOARD[ny][nx]
        ret = max(cur, ret)

    return ret

N, M = map(int, input().split())
BOARD = list(list(map(int, input().split())) for _ in range(N))
    
ans = 0
for y in range(N):
    for x in range(M):
        ans = max(ans, check(x, y))
print(ans)
