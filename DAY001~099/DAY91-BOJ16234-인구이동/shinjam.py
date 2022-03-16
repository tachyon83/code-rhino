from collections import deque

N, L, R = map(int, input().split())
A = list(list(map(int, input().split())) for _ in range(N))


def get_kingdoms(start_x, start_y, visited):
    dx, dy = (1, 0, -1, 0), (0, 1, 0, -1)
    queue = deque([(start_x, start_y)])
    visited.add((start_x, start_y))
    member_sum, kingdoms = A[start_y][start_x], {(start_x, start_y)}
    while queue:
        x, y = queue.popleft()

        for v in range(4):
            nx, ny = x + dx[v], y + dy[v]
            if not (0 <= nx < N and 0 <= ny < N):
                continue
            if (nx, ny) in kingdoms or (nx, ny) in visited:
                continue
            if L <= abs(A[y][x] - A[ny][nx]) <= R:
                queue.append((nx, ny))
                kingdoms.add((nx, ny))
                visited.add((nx, ny))
                member_sum += A[ny][nx]

    return member_sum, kingdoms


def cycle():
    visited = set()
    ret = False
    for idx in range(N ** 2):
        r, c = idx // N, idx % N
        member_sum, kingdoms = get_kingdoms(c, r, visited)
        moved = member_sum // len(kingdoms)
        for x, y in kingdoms:
            A[y][x] = moved
        if len(kingdoms) > 1:
            ret = True
    return ret


ans = 0
while cycle():
    ans += 1
print(ans)
