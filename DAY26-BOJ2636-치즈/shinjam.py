from collections import deque

def get_cheeses(desk):
    ret = set()
    for idx in range(col * row):
        c, r = divmod(idx, row)
        if desk[c][r] == 1:
            ret.add((r, c))
    return ret


def will_melts(cheeses, visited):
    queue = deque([(0, 0)])
    melts = set()
    while queue:
        x, y = queue.popleft()
        if desk[y][x] == 1:
            melts.add((x, y))
            continue
        for v in range(4):
            nx, ny = x + dx[v], y + dy[v]
            if all([0<=nx<row, 0<=ny<col]) and (nx, ny) not in visited:
                visited.add((nx, ny))
                queue.append((nx, ny))
    for x, y in melts:
        desk[y][x] = 0
    return melts


col, row = map(int, input().split())
desk = [list(map(int, input().split()))for _ in range(col)]
cheeses = get_cheeses(desk)
time, left_cnt = 0, 0

dx, dy = (1, 0, -1, 0), (0, 1, 0, -1)

while cheeses:
    left_cnt = len(cheeses)
    cheeses -= will_melts(cheeses, set())
    time += 1
    
print(time)
print(left_cnt)
