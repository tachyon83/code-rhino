import sys
from collections import deque

def bfs(mid):
    q = deque()
    q.append(start)
    visited = set()
    visited.add(start)
    while q:
        s = q.popleft()
        for e, w in maps[s]:
            if e in visited or w < mid:
                continue
            visited.add(e)
            q.append(e)
    return True if end in visited else False

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    maps = [[] for _ in range(n+1)]

    _min, _max = 1, 1000000000

    for _ in range(m):
        y, x, cost = map(int, sys.stdin.readline().split())
        maps[y].append((x, cost))
        maps[x].append((y, cost))

    start, end = map(int, sys.stdin.readline().split())

    res = _min

    while _min <= _max:
        mid = (_min + _max) // 2

        if bfs(mid):
            res = mid
            _min = mid+1
        else:
            _max = mid - 1
    print(res)
