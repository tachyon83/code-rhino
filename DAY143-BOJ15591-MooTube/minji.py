import sys
from collections import deque

def bfs():
    ans = 0
    q = deque([])
    q.append(v)
    visited = [0] * (n+1)
    visited[v] = 1
    while q:
        tmp = q.popleft()
        for dis, i in maps[tmp]:
            if dis >= k and visited[i] == 0:
                visited[i] = 1
                q.append(i)
                ans += 1
    return ans

if __name__ == "__main__":
    n, q = map(int, sys.stdin.readline().split())

    maps = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        a, b, c = map(int, sys.stdin.readline().split())
        maps[a].append([c, b])
        maps[b].append([c, a])

    for _ in range(q):
        k, v = map(int, sys.stdin.readline().split())
        ans = bfs()
        print(ans)
