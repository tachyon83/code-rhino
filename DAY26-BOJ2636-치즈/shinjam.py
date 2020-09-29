from collections import deque


def will_melts():
    queue = deque([(0, 0)])
    visited, melts = set(), set()
    while queue:
        x, y = queue.popleft()
        if desk[y][x] == 1:
            melts.add((x, y))
            continue
        for v in range(4):
            nx, ny = x + dx[v], y + dy[v]
            if (0<=nx<row and 0<=ny<col) and (nx, ny) not in visited:
                visited.add((nx, ny))
                queue.append((nx, ny))
    for x, y in melts:
        desk[y][x] = 0
    return len(melts)


col, row = map(int, input().split())
desk = [list(map(int, input().split()))for _ in range(col)]
cheeses = sum(sum(desk, []))
time, left_cnt = 0, 0

dx, dy = (1, 0, -1, 0), (0, 1, 0, -1)

while cheeses:
    left_cnt = cheeses
    cheeses -= will_melts()
    time += 1
    
print(time)
print(left_cnt)
