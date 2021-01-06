from collections import deque


def check(gears, start, direction):
    status, visited = [0] * 4, [0] * 4
    status[start], visited[start] = direction, 1
    queue = deque([(start, direction)])

    while queue:
        idx, d = queue.popleft()
        for v in 1, -1:
            nd = None
            nidx = idx + v
            if not 0 <= nidx < 4:
                continue
            if visited[nidx]:
                continue
            if not d:
                continue
            visited[nidx] = 1
            
            if (v == 1 and gears[idx][2] != gears[nidx][6]) or (v == -1 and gears[idx][6] != gears[nidx][2]):
                nd = d * -1
                status[nidx] = nd
            queue.append((nidx, nd))
    for idx, val in enumerate(status):
        if val:
            gears[idx].rotate(val)


gears = list()
for _ in range(4):
    gears.append(deque(map(int, input())))

for _ in range(int(input())):
    idx, direction = map(int, input().split())
    check(gears, idx-1, direction)


ans = 0
for idx, val in enumerate(gears):
    if val[0]:
        ans += 2** idx
print(ans)
