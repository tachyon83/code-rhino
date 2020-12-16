import sys
sys.setrecursionlimit(10**6)

lined = {(0, 0)}
for _ in range(int(input())):
    pos = map(int, input().split())
    x1, x2, y1, y2 = *sorted([pos[0]*2, pos[2]*2]), *sorted([pos[1]*2, pos[3]*2])
    for x in range(x1, x2+1):
        lined.add((x, y1))
        lined.add((x, y2))
    for y in range(y1, y2+1):
        lined.add((x1, y))
        lined.add((x2, y))

dx, dy = (1, 0, -1, 0), (0, 1, 0, -1)
def dfs(x, y):
    if (x, y) in lined:
        lined.remove((x, y))
        for v in range(4):
            nx, ny = x+dx[v], y+dy[v]
            if not all([-1000<=nx<=1000, -1000<=ny<=1000]):
                continue
            dfs(nx, ny)
    return 1
        
cnt = -1
while lined:
    cnt += dfs(*next(iter(lined)))
    
print(cnt)
